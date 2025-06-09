module Serialized_Comparator_tb;

import std.stdio;
import esdl;
import uvm;

void main()
{
    CommandLine cmdl =  new CommandLine(args);


}

class testbench: uvm_tb
{
    Top top;

    override void initial()
    {
        uvm_config_tb!(comp_in_intf).set(null, "uvm_test_top.env.agent.driver", "comp_in", top.compin);
        uvm_config_tb!(comp_out_intf).set(null, "uvm_test_top.env.agent.driver", "comp_out", top.compout);

    }
}

class Top: Entity
{
    //Initializing Verilator to obtain the trace
    VerilatedVcdD trace;

    ///Declaring unsigned bit signals for clock and reset
    Signal!(ubvec!1) clock;
    Signal!(ubvec!1) reset;

    //Declaring the design Under test (DUT) to be read after going through verilator
    DVMulti_Bit_Comparator_Serialized dut;

    comp_in_intf compin;
    comp_out_intf compout;

    void openTrace(string vcdname)
    {
        if(trace is null)
        {
            trace = new VerilatedVcdD();
            dut.trace(trace, 99);
            trace.open(vcdname);
        }
    }

    void closeTrace()
    {
        if(trace !is null)
        {
            trace.close();
            trace = null;
        }
    }

    override void connections()
    {
        //Input connections
        compin.clock(clock);
        compin.reset(reset);

        compin.a_in(dut.a_in);
        compin.b_in(dut.b_in);

        //Output connections
        compout.clock(clock);
        compout.reset(reset);

        compout.less_than(dut.less_than);
        compout.equal_to(dut.equal_to);
        compout.greater_than(dut.greater_than);
    }

    void build()
    {
        dut = new DVMulti_Bit_Comparator_Serialized;
        traceEverOn(true);
        opentrace("Multi_Bit_Comparator_Serialized.vcd");
    }

    Task!stimulateClock stiulateClockTask;
    Task!stumulateReset stimulateResetTask;

    void stiumulateClock()
    {
        clock = false;
        
        for(size_t i=1; i<10000; i++)
        {
            clock = false;
            dut.clk = false;

            wait (2.nsec);
            dut.eval();

            wait(8.nsec);
            clock = true;
            dut.clk = true;

            wait(2.nsec);
            dut.eval;
            wait(8.nsec);
        }
    }

    void stimulateReset()
    {
        reset = true;
        dut.reset = true;

        wait (30.nsec);

        reset = false;
        dut.reset = false;
    }
}

class comp_in_intf: VlInterface
{
    //Interface to for input ports of the design
    Port!(Signal!(ubvec!1)) clock;
    Port!(Signal!(ubvec!1)) reset;

    VlPort!1 a_in, b_in;
}

class comp_out_intf: VlInterface
{
    //interface for output ports of the design
    Port!(Signal!(ubvec!1)) clock;
    Port!(Signal!(ubvec!1)) reset;

    VlPort!1 less_than, equal_to, greater_than;
}

class comp_env: uvm_env
{
    mixin uvm_component_utils;

    @UVM_BUILD private comp_agent agent;

    this(string name, uvm_component parent) { super(name, parent); }
}

class random_test: uvm_test
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent) { super(name, parent); }

    @UVM_BUILD { comp_env env; phrase }
  
    override void run_phase(uvm_phase phase) 
    {
        phase.get_objection().set_drain_time(this, 100.nsec);
        phase.raise_objection(this);
        comp_seq rand_sequence = comp_seq.type_id.create("comp_seq");

        for (size_t i=0; i!=100; ++i) 
        {
            rand_sequence.randomize();
            auto sequence = cast(comp_seq) rand_sequence.clone();
            sequence.start(env.agent.sequencer, null);
        }
        
        phase.drop_objection(this);
    }
}

class comp_agent: uvm_agent
{
    //////////////////////
}

class comp_sequencer: uvm_sequencer!comp_item
{
  mixin uvm_component_utils;

  this(string name, uvm_component parent=null) { super(name, parent); }
}

class comp_monitor: uvm_monitor
{

    mixin uvm_component_utils;
    
    @UVM_BUILD 
    {
        uvm_analysis_port!comp_seq egress;
        uvm_analysis_imp!(comp_monitor, write) ingress;
    }


    this(string name, uvm_component parent = null) { super(name, parent); }

    comp_seq seq;

    void write(comp_item item) 
    {
        if (seq is null)
            seq = comp_seq.type_id.create("comp_seq");
        
        seq ~= item;
        
        if (seq.is_finalized()) 
        {
            uvm_info("Monitor", "Got Seq " ~ seq.sprint(), UVM_DEBUG);
            egress.write(seq);
            seq = null;
        }
    }
}

class comp_scoreboard: uvm_scoreboard
{
    this(string name, uvm_component parent = null) { super(name, parent); }

    mixin uvm_component_utils;

    uvm_phase phase_run;

    uint matched;

    comp_seq[] req_queue;
    comp_seq[] rsp_queue;

    @UVM_BUILD 
    {
        uvm_analysis_imp!(comp_scoreboard, write_req) req_analysis;
        uvm_analysis_imp!(comp_scoreboard, write_rsp) rsp_analysis;
    }

    override void run_phase(uvm_phase phase) 
    {
        phase_run = phase;
        auto imp = phase.get_imp();
        assert(imp !is null);
        uvm_wait_for_ever();
    }

    void write_req(comp_seq seq) 
    {
        uvm_info("Monitor", "Got req item", UVM_DEBUG);
        
        req_queue ~= seq;
        assert(phase_run !is null);
        
        phase_run.raise_objection(this);
    }

    void write_rsp(comp_seq seq) 
    {
        uvm_info("Monitor", "Got rsp item", UVM_DEBUG);
        
        rsp_queue ~= seq;
        assert(phase_run !is null);
        
        check_matched();
        phase_run.drop_objection(this);
    }

    void check_matched() 
    {
        auto expected = req_queue[matched].transform();
        
        if (expected == rsp_queue[matched].phrase) ///////////////////////////////////////////////////
        {
            uvm_info("MATCHED", format("Scoreboard received expected response #%d", matched), UVM_LOW);
            uvm_info("REQUEST", format("%s", req_queue[$-1].phrase), UVM_LOW);
            uvm_info("RESPONSE", format("%s", rsp_queue[$-1].phrase), UVM_LOW);
        }
        else 
        {
            uvm_error("MISMATCHED", "Scoreboard received unmatched response");
            writeln(expected, " != ", rsp_queue[matched].phrase);
        }
        
        matched += 1;
    }
}

class comp_driver: uvm_driver!(comp_item)
{

    mixin uvm_component_utils;
    
    comp_in_intf comp_in;

    this(string name, uvm_component parent = null) 
    {
        super(name, parent);
        uvm_config_db!comp_in_intf.get(this, "", "comp_in", comp_in);
        assert (comp_in !is null);
    }

    override void run_phase(uvm_phase phase) 
    {
        super.run_phase(phase);
        while (true) 
        {
            seq_item_port.try_next_item(req);

            if (req !is null) 
            {
                for (int i = 0; i != req.delay; ++i)
                    wait (comp_in.clock.negedge());
                
                while (comp_in.solved == 0 || comp_in.reset == 1)
                    wait (comp_in.clock.negedge());

                wait (comp_in.clock.negedge());

                comp_in.a_in = req.a_in;
                comp_in.b_in = req.b_in;
                
                seq_item_port.item_done();
            }
            else
                wait (comp_in.clock.negedge());
        }
    }
}

class comp_seq: uvm_sequence!comp_item
{
    @UVM_DEFAULT { @rand uint seq_size; }

    mixin uvm_object_utils;

    this(string name="") 
    {
        super(name);
        req = comp_item.type_id.create(name ~ ".req");
    }

    constraint! q{
        seq_size < 200;
        seq_size > 16;
    } seq_size_cst;
    
    override void body() 
    {
        for (size_t i=0; i!=seq_size; ++i)
        {
            wait_for_grant();
            req.randomize();
            
            if (i == seq_size - 1) req.end = true;
            else req.end = false;
            
            comp_item cloned = cast(comp_item) req.clone;
            
            send_request(cloned);
        }
    }

    ubvec!3[] transform() 
    {
        ubvec!3[] retval;
        ubvec!1 less_than, equal_to, greater_than;
        
        less_than = (a < b);
        equal_to = (a == b);
        greater_than = (a > b);

        retval ~= (less_than ~ equal_to ~ greater_than);

        return retval;
    }
}

class comp_item: uvm_sequence_item
{
    mixin uvm_object_utils;

    @UVM_DEFAULT { @rand uint a_in, b_in; }
    
    this(string name = "comp_item") { super(name); }

    constraint! q{
        a_in < 256;
        b_in < 256;

        a_in > 0;
        b_in > 0;
    } input_cst;
}