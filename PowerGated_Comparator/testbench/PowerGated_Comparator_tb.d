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
        @rand ubyte a, b;

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
    //Adding utilitiesfor
    //Sequencer is a component, hence component_utils
    mixin uvm_component_utils;

    //Mandatory constructor to initialize class
    //Components will always have a parent 
    this(string name, uvm_component parent=null) { super(name, parent); }
}

//Sequence
class seq: uvm_sequence!(item)
{
    mixin uvm_object_utils;

    item comp;

    //Mandatory constructor, no parent for Objects
    this(string name="") 
    { 
        super(name); 
        
        comp = item.type_id.create("comp");
    }

    int n = 5;

/*    constraint! q{
        n > 5;
        n < 10;
    } seq_constraint;
*/

    override void body()
    {
        for(int i=0; i<n; i++)
        {
            wait_for_grant();
            comp.randomize();

            writeln("Generated Item %d", i);

            item cloned = cast(item) comp.clone;
            send_request(cloned);
        }

        uvm_info("SEQ", format("%d ITEMS GENERATED", n), UVM_LOW);
    }
}

//Interface
class intf: VlInterface
{
    //Fixed ports
    Port!(Signal!(ubvec!1)) clock;
    
    VlPort!1 reset;

    //Input virtual ports
    VlPort!8 a_in, b_in;

    //Output virtual ports
    VlPort!1 less_than, greater_than, equal_to, solved;
}

//Driver
class driver: uvm_driver!(item)
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
        super.run_phase(phase);

        //Toggling the input pins as oer the design
        while(true)
        {
            writeln("Driver is running");

            //Fetching an item and storing it in allocated memory
            seq_item_port.get_next_item(req);

            uvm_info(get_type_name(), "Got new item", UVM_LOW);

            //Actual driving of them inputs
            //This can be written in another function and called also
             
            //The 'solved' control signal indicates that the operation is completed

            uvm_info(get_full_name(), "THis works", UVM_LOW);

            if(vif.solved)
            {    //The reset is active-high, and must be triggered before the next input
                vif.reset = true;

                wait(vif.clock.posedge());
                uvm_info("DRIVER", "Design has been reset", UVM_LOW);
            }
            else
            {
                //The reset is set to low and the inputs are provided
                vif.reset = false;
                vif.a_in = req.a;
                vif.b_in = req.b;

                uvm_info("DRIVER", "Inputs have been provided", UVM_LOW);
            }

            //Adding delay of one clock cycle between each step to synchronize read and write
            wait(vif.clock.posedge());

            //Declaring the item as done so that it can proceed to the next step
            seq_item_port.item_done();
        }
    }
}

//Monitor
class monitor: uvm_monitor//!(item)
{
    mixin uvm_component_utils;

    intf vif;

    @UVM_BUILD
    {
        uvm_analysis_port!item mon_analysis_port;
    }

    this(string name, uvm_component parent = null) 
    { 
        super(name, parent);

        uvm_config_db!intf.get(this, "", "vif", vif); 
        assert(vif !is null);
    }

    //Building the analysis port to send data out to Scoreboard
    override void build_phase(uvm_phase phase)
    {
        super.build_phase(phase);
    }

    override void run_phase(uvm_phase phase)
    {
        super.run_phase(phase);

        while(true)
        {
            writeln("Monitor is running");

            wait(vif.clock.posedge());

            item comp = item.type_id.create("comp");

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
                uvm_info("MONITOR", comp.sprint(), UVM_LOW);

                //Writing the item to the scoreboard for checking
                mon_analysis_port.write(comp);

                uvm_info("MONITOR", "Comparison done", UVM_LOW);
            }
        }
    }
}

//Agent
class agent: uvm_agent
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    driver comp_driver;
    monitor comp_monitor;
    sequencer comp_sequencer;

    override void build_phase(uvm_phase phase)
    {
        super.build_phase(phase);

        comp_driver = driver.type_id.create("comp_driver", this);
        comp_monitor = monitor.type_id.create("comp_monitor", this);
        comp_sequencer = sequencer.type_id.create("comp_sequencer", this);

        uvm_info("AGENT", "Agent is done building", UVM_LOW);
    }

    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        comp_driver.seq_item_port.connect(comp_sequencer.seq_item_export);
        
        uvm_info("AGENT", "Agent has connected sub-components", UVM_LOW);
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

    override void build_phase(uvm_phase phase)
    {
        super.build_phase(phase);
    }

    void write(item comp)
    {
        uint a = comp.a, b = comp.b;

        if(comp.less_than == (a<b) && comp.greater_than == (a>b) && comp.equal_to == (a==b))
            uvm_info("MATCHED", "Comparison is Correct", UVM_LOW);
        else
        {
            uvm_error("ERROR", "Comparison is Incorrect");
            writeln("Expected: \n less_than = ", (a<b), "\n greater_than = ", (a>b), "\n equal_to = ", (a==b));
        }
    }
}

//Enviroment
class env: uvm_env
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    agent comp_agent;
    scoreboard comp_scoreboard;
    
    override void build_phase(uvm_phase phase)
    {
        super.build_phase(phase);

        comp_agent = agent.type_id.create("comp_agent", this);
        comp_scoreboard = scoreboard.type_id.create("comp_scoreboard", this);

        uvm_info("ENVIRONMENT", "Environment is done building", UVM_LOW);
    }

    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        comp_agent.comp_monitor.mon_analysis_port.connect(comp_scoreboard.mon_analysis_imp);

        writeln("Environment has connected sub-components");
    }
}

//Test
class test: uvm_test
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    intf vif;
    
    env comp_env;

    override void build_phase(uvm_phase phase)
    {
        super.build_phase(phase);

        comp_env = env.type_id.create("comp_env", this);

        writeln("Test is done building");
    }
    
    override void run_phase(uvm_phase phase)
    {
        writeln("Starting test");
        
        //Set duration for twhich the test will run
        //Since clock period is set to 20ns, a time of 200ns will read 10 clock cycles
        phase.get_objection().set_drain_time(this, 200.nsec);

        phase.raise_objection(this);

        seq comp_seq = seq.type_id.create("comp_seq");

        uvm_info("TEST", "Test has started", UVM_LOW);
        
        comp_seq.randomize();
        comp_seq.start(comp_env.comp_agent.comp_sequencer, null);
        //uvm_info(get_full_name(), "Sequence has started", UVM_LOW);

/*        for(size_t i=0; i!=10; i++)
        {   
            //uvm_info("TEST", format("Generated Sequence %d", i), UVM_LOW);
            writeln("Generated Sequence ", (i+1));

            comp_seq.randomize();

            auto clone_seq = cast(seq) comp_seq.clone();

            clone_seq.start(comp_env.comp_agent.comp_sequencer, null);

            uvm_info(get_full_name(), "Sequence has started", UVM_LOW);
        }
*/
        //Setting the path for the sequence to start: Environment -> Agent -> Sequencer
        comp_seq.start(comp_env.comp_agent.comp_sequencer);

        uvm_info("TEST", "Test is complete", UVM_LOW);

        uvm_info("RESULT", format("Matched: %d\nErrors: %d", comp_env.comp_scoreboard.matched, comp_env.comp_scoreboard.errors), UVM_LOW);

        phase.drop_objection(this);
    }
}

//TopClock
class Top: Entity
{
    import VMulti_Bit_Comparator_PowerGated_euvm;
    import esdl.intf.verilator.verilated;
    import std.stdio;

    VerilatedVcdD trace;
    DVMulti_Bit_Comparator_PowerGated dut;

    intf vif;

    Signal!(ubvec!1) clock;

    void opentrace(string vcdname)
    {
        if(trace is null)
        {
            trace = new VerilatedVcdD();
            dut.trace(trace, 99);
            trace.open(vcdname);

            writeln("Trace is open");
        }
    }

    void closetrace()
    {
        if(trace !is null)
        {
            trace.close();
            trace = null;

            writeln("Trace is closed");
        }
    }

    override void doConnect()
    {
        //Clock
        vif.clock(clock);

        //Inputs
        vif.reset(dut.reset);
        vif.a_in(dut.a_in);
        vif.b_in(dut.b_in);
        
        //Outputs
        vif.less_than(dut.less_than);
        vif.greater_than(dut.greater_than);
        vif.equal_to(dut.equal_to);
        vif.solved(dut.solved);
    
        writeln("Interface is connected to Design");
    }

    override void doBuild()
    {
        dut = new DVMulti_Bit_Comparator_PowerGated();
        traceEverOn(true);
        opentrace("Multi_Bit_Comparator_PowerGated.vcd");

        writeln("Design is built");
    }

    Task!stimulateClock stimulateClockTask;

    void stimulateClock()
    {
        clock = false;
        for(size_t i=0; i<10; i++)
        {
            clock = false;
            dut.clock = false;

            wait(5.nsec);
            dut.eval();
            if(trace !is null) trace.dump(getSimTime().getVal());

            clock = true;
            dut.clock = true;
            wait(5.nsec);
            dut.eval();

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
        uvm_config_db!(intf).set(null, "uvm_test_top.comp_env.comp_agent.comp_driver", "vif", top.vif);
        uvm_config_db!(intf).set(null, "uvm_test_top.comp_env.comp_agent.comp_monitor", "vif", top.vif);
    
        writeln("Tetsbench has been initialized");
    }
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
