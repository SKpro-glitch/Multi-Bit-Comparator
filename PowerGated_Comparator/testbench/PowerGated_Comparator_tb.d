import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

//Item
class item: uvm_sequence_item
{
    //Adding utilities
    //Item is an object, hence object_utils
    mixin uvm_object_utils;

    @UVM_DEFAULT {
        //Inputs
        @rand uint a, b;

        //Outputs
        ubvec!1 less_than, greater_than, equal_to;
    }

    //Mandatory constructor to initialize class
    //Object will not have a parent 
    this(string name ="item") { super(name); }

    //No constraints needed for this design
    constraint! q{
        a < 256;
        b < 256;
    } comp_constraints;
}

//Sequencer
class sequencer: uvm_sequencer!item
{
    //Adding utilities
    //Sequencer is a component, hence component_utils
    mixin uvm_component_utils;

    //Mandatory constructor to initialize class
    //Components will always have a parent 
    this(string name, uvm_component parent=null) { super(name, parent); }
}

//Sequence
class seq: uvm_sequence
{
    mixin uvm_object_utils;

    //Mandatory constructor
    this(string name, uvm_component parent = null) { super(name, parent); }

    @rand int n;

    constraint! q{
        n > 5;
        n < 10;
    } seq_constraint;

    override void body()
    {
        for(int i=0; i<n; i++)
        {
            item comp;

            start_item(comp);
            comp.randomize();
            writeln("New item: ");
            comp.print();
            finish_item(comp);
        }

        uvm_info("SEQ", format("%d ITEMS GENERATED", n), UVM_LOW);
    }
}

//Interface
class intf: VlInterface
{
    //Fixed ports
    Port!(Signal!(ubvec!1)) clock;
    Port!(Signal!(ubvec!1)) reset;

    //Input virtual ports
    VlPort!8 a_in, b_in;

    //Output virtual ports
    VlPort!1 less_than, greater_than, equal_to, solved;
}

//Driver
class driver: uvm_driver!item
{
    mixin uvm_component_utils;

    //Instantiating a virtual interface
    intf vif;

    //Mandatory constructor
    this(string name, uvm_component parent = null)
    {
        super(name, parent);

        //Verifying that the virtual interface is instantiated successfully 
        uvm_config_db!intf.get(this, "", "vif", vif);
        assert(vif !is null);
    }

    //Build phase - Nothing to build in the Driver
    //@UVM_BUILD {}

    //Run phase - driving the input values
    //Naming is mandatory
    override void run_phase(uvm_phase phase)
    {
        super.run(phase);

        //Toggling the input pins as oer the design
        while(true)
        {
            item comp;

            //Fetching an item and storing it in allocated memory
            seq_item_port.try_next_item(comp);

            //Actual driving of them inputs
            //This can be written in another function and called also
             
            //The 'solved' control signal indicates that the operation is completed
            if(solved)
                //The reset is active-high, and must be triggered before the next input
                vif.reset = 1;
            else
            {
                //The reset is set to low and the inputs are provided
                vif.reset = 0;
                vif.a_in = comp.a_in;
                vif.b_in = comp.b_in;
            }

            //Adding delay of one clock cycle between each step to synchronize read and write
            wait(vif.clock.posedge());

            //Declaring the item as done so that it can proceed to the next step
            seq_item_port.item_done();
        }
    }
}

//Monitor
class monitor: uvm_monitor!item
{
    mixin uvm_component_utils;

    intf vif;

    this(string name, uvm_component parent = null) 
    { 
        super(name, parent);

        uvm_config_db!intf.get(this, "", "vif", vif); 
        assert(vif !is null);
    }

    //Building the analysis port to send data out to Scoreboard
    @UVM_BUILD
    {
        uvm_analysis_port!item mon_analysis_port;
    }

    override void run_phase(uvm_phase phase)
    {
        super.run_phase(phase);

        while(true)
        {
            item comp;

            if(vif.solved)
            {
                //Reading the input values for reference
                comp.a = vif.a_in;
                comp.b = vif.b_in;

                //Reading the output values for checking
                comp.less_than = vif.less_than;
                comp.greater_than = vif.greater_than;
                comp.equal_to = vif.equal_to;

                //Printing item for reference
                comp.sprint();

                //Writing the item to the scoreboard for checking
                mon_analysis_port.write(comp);
            }
            else wait(vif.clock.posedge());
        }
    }
}

//Agent
class agent: uvm_agent
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    @UVM_BUILD
    {
        driver d0;
        monitor m0;
        sequencer s0;
    }

    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        d0.seq_item_port.connect(s0.seq_item_export);
    }
}

//Scoreboard
class scoreboard: uvm_scoreboard
{
    mixin uvm_component_utils;

    uint matched, errors;

    this(string name, uvm_component parent = null) { super(name, parent); }

    @UVM_BUILD
    {
        //Add the class and function to which the port will send data
        uvm_analysis_imp!(scoreboard, write) mon_analysis_imp;
    }

    void write(item comp)
    {
        uint a = comp.a, b = comp.b;

        if(comp.less_than == (a<b) && comp.greater_than == (a>b) && comp.equal_to == (a==b))
            uvm_info("MATCHED", "Comparison is Correct", UVM_LOW);
        else
        {
            uvm_error("ERROR", "Comparison is Incorrect", UVM_LOW);
            writeln("Expected: less_than = %s, greater_than = %s, equal_to = %s", (a<b), (a>b), (a==b));
        }
    }
}

//Enviroment
class env: uvm_env
{
    mixin uvm_componet_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    @UVM_BUILD
    {
        agent a0;
        scoreboard sb0;
    }
    
    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        a0.m0.mon_analysis_port.connect(sb0.mon_analysis_imp);
    }
}

//Test
class test: uvm_test
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    @UVM_BIULD
    {
        env e0;
        intf vif;
    }

    override void run_phase(uvm_phase phase)
    {
        seq comp_seq;

        //Set duration for twhich the test will run
        //Since clock period is set to 20ns, a time of 200ns will read 10 clock cycles
        phase.get_objection().set_drain_time(this, 200.nsec);

        phase.raise_objection();

        comp_seq.randomize();
        //Setting the path for the sequence to start: Environment -> Agent -> Sequencer
        comp_seq.start(e0.a0.s0);

        writeln("Matched: %d\nErrors: %d", e0.sb0.matched, e0.sb0.errors);

        phase.drop_objection();
    }
}

//Top
class top: Entity
{
    import VMulti_Bit_Comparator_PowerGated_euvm;
    import esdl.intf.verilator.verilated;
    import std.stdio;

    VerilatedVcdD trace;
    DVMulti_Bit_Comparator_PowerGated dut;

    intf vif;

    Signal!(ubvec!1) clock, reset;

    void opentrace(string vcdname)
    {
        if(trace is null)
        {
            trace = new VerilatedVcdD();
            dut.trace(trace, 99);
            trace.open(vcdname);
        }
    }

    void closetrace()
    {
        if(trace !is null)
        {
            trace.close();
            trace = null;
        }
    }

    override void doConnect()
    {
        //Clock and Reset
        vif.clock(clock);
        vif.reset(reset);

        //Inputs
        vif.a_in(dut.a_in);
        vif.b_in(dut.b_in);
        
        //Outputs
        vif.less_than(dut.less_than);
        vif.greater_than(dut.greater_than);
        vif.equal_to(dut.equal_to);
        vif.solved(dut.solved);
    }

    override void doBuild()
    {
        dut = new DVMulti_Bit_Comparator_PowerGated();
        traceEverOn(true);
        opentrace("Multi_Bit_Comparator_PowerGated.vcd");
    }

    Task!Clock Clock;

    void Clock()
    {
        clock = false;
        for(size_t i=0; i<1000; i++)
        {
            clock = false;
            dut.clock = false;

            wait(10.nsec);
            dut.eval();
            if(trace !is null) trace.dump(getSimTime().getVal());

            clock = true;
            dut.clock = true;
            if(trace !is null) 
            {
                trace.dump(getSimTime().getVal());
                trace.flush();
            }
        }
    }
}

//Testbench module to instantiate Top
class testbench: uvm_tb
{
    Top top;

    override void initial()
    {
        //Connecting the driver and monitor to interface
        uvm_config_db!(intf).set(null, "uvm_test_top.env.agent.driver", "vif", top.intf);
        uvm_config_db!(intf).set(null, "uvm_test_top.env.agent.monitor", "vif", top.intf);
    }

    void main(string[] args)
    {
        import std.stdio;

        uint seed;

        CommandLine cmdl = new CommandLine(args);

        if(cmdl.plusArgs("seed = " ~ "%d", seed)) writeln("Using random seed: %d", seed);
        else seed = 1;

        auto tb = new testbench;

        tb.multicore(0, 1);
        tb.elaborate("tb", args);
        tb.set_seed(seed);
        tb.start();
    }
}