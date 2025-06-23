import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

/**
//Item
// This is the base transaction object that will be used in the environment to initiate new transactions and capture transactions at DUT interface
class item: uvm_sequence_item
{
    //Adding utilities
    //Item is an object, hence 'uvm_object_utils'
    mixin uvm_object_utils;

    @UVM_DEFAULT {
        //Inputs - randomized
        @rand ubyte a, b;

        //Outputs - not randomized
        ubvec!1 less_than, greater_than, equal_to;
    }

    //Mandatory constructor to initialize class
    //Object will not have a parent 
    this(string name ="item") { super(name); }

    //No constraints needed for this design
    constraint! q{} comp_constraints;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sequencer
//The sequencer is a mediator who establishes a connection between sequence and driver
class sequencer: uvm_sequencer!item
{
    //Adding utilities
    //Sequencer is a component, hence component_utils
    mixin uvm_component_utils;

    //Mandatory constructor to initialize class
    //Components will always have a parent 
    this(string name, uvm_component parent=null) { super(name, parent); }

    //No phases needed for Sequencer
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sequence
//The main sequence that forms the stimulus and randomizer aspect of the testbench
class seq: uvm_sequence!(item)
{
    mixin uvm_object_utils;

    item comp;
    
    //Mandatory constructor, no parent for Objects
    this(string name="") { super(name); }

    //Number of sequences
    @rand int n; 

    //Can be randomized also, fixed also
    //It is randomized when applicable in multi-cycle designs, or data streams
    //Example: FIFO, Avalon stream etc.

    constraint! q{
        n > 5;
        n < 10;
    } seq_constraint;

    //Functions that need to be overridden are in-built
    //Their names should not be changed
    override void body()
    {
        comp = item.type_id.create("comp");

        for(int i=0; i<n; i++)
        {
            wait_for_grant();
            comp.randomize();

            uvm_info("SEQ", format("Generated Item No. %d", i), UVM_HIGH);

            //Cloning of item is not necessary
            //It is useful when making a reference model
            //Cloned item is sent to driver and Original is sent to scoreboard
            //No reference model made here
            
            item cloned = cast(item) comp.clone;
            send_request(cloned);
        }

        uvm_info("SEQ", format("%d ITEMS GENERATED", n), UVM_LOW);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Interface
//Interface allows verification components to access DUT signals using a virtual interface handle
//Interface is virtual for dynamic instantiation 
class intf: VlInterface
{
    //Fixed ports - posedge and negedge can be checked only on these
    Port!(Signal!(ubvec!1)) clock;
    
    //Verilated Ports - Posedge / Negedge cannot be checked on these
    
    //Input ports - Verilated
    VlPort!1 reset;
    VlPort!8 a_in, b_in;

    //Output ports - Verilated
    VlPort!1 less_than, greater_than, equal_to, solved;

    //Clocking block, like that in SystemVerilog, is not required here
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Driver
//Drives oinputs of the Design Under Test (DUT)
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
    //override void build() {}
    
    //Run phase - driving the input values
    //Overridden function, consistent naming is mandatory
    override void run_phase(uvm_phase phase)
    {
        //Passing the phase to the parent class
        super.run_phase(phase);

        //Toggling the input pins as per the design
        //Always inside an infinite loop
        while(true)
        {
            uvm_info("DRIVER", "Driver is running", UVM_HIGH);

            //Fetching an item and storing it in allocated memory
            seq_item_port.get_next_item(req);
            //The item 'req' is a built-in item which takes the value of the item originally passed as argument to the UVM class

            uvm_info(get_type_name(), "Got new item", UVM_MEDIUM);

            //Actual driving of them inputs
            //This can be written in another function and called also
            
            //Design-specific requirement: The design must be reset before every new input
            vif.reset = true;

            //One clock cycle is needed for the reset to be evaluated
            wait(vif.clock.posedge());
            
            //Setting the active-high reset back to low and passing the inputs
            vif.reset = false;
            vif.a_in = req.a;
            vif.b_in = req.b;

            uvm_info("DRIVER", "Inputs have been provided", UVM_MEDIUM);
            
            //Waiting one clock cycle before resetting again 
            wait(vif.clock.posedge());
            
            //Declaring the item as done so that it can proceed to the next step
            seq_item_port.item_done();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Monitor
//Fetches and reads output from the DUT
class monitor: uvm_monitor
{
    mixin uvm_component_utils;

    intf vif;

    //The UVM_BIULD syntax simplifies and automates the build phase
    //Useful for simple things like ports
    @UVM_BUILD
    {
        //The analysis port takes the output values and sends them to the scoreboard for evaluation
        uvm_analysis_port!item mon_analysis_port;
    }

    this(string name, uvm_component parent = null) 
    { 
        super(name, parent);

        uvm_config_db!intf.get(this, "", "vif", vif); 
        assert(vif !is null);
    }

    //The build_phase function is more customizable than UVM_BUILD
    //override void build_phase(uvm_phase phase) {}

    item comp;

    override void run_phase(uvm_phase phase)
    {
        super.run_phase(phase);

        while(true)
        {
            //Waiting 2 clock cycles - 1 for reset, 1 for input
            wait(vif.clock.posedge());
            wait(vif.clock.posedge());
            
            //Synchronization of clock cycles is design specific
            //This can also be put inside a loop if needed
             
            //if(vif.solved)
            {
                //Instantiating new item to fetch the values from interface
                comp = item.type_id.create("comp");

                //Reading the input values for reference
                comp.a = vif.a_in;
                comp.b = vif.b_in;

                //Reading the output values for checking
                comp.less_than = vif.less_than;
                comp.greater_than = vif.greater_than;
                comp.equal_to = vif.equal_to;

                //Printing item for reference and manual verification
                uvm_info("MONITOR", comp.sprint(), UVM_LOW);

                //Writing the item to the scoreboard for checking
                mon_analysis_port.write(comp);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Agent
//Containerize the sequencer, driver and monitor on to a common platform
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

        //All sub-components must be intantiated in the build phase
        comp_driver = driver.type_id.create("comp_driver", this);
        comp_monitor = monitor.type_id.create("comp_monitor", this);
        comp_sequencer = sequencer.type_id.create("comp_sequencer", this);

        uvm_info("AGENT", "Agent is done building", UVM_HIGH);
    }

    //Connect phase connects the sub-components as required
    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        //Connecting the sequencer to driver
        comp_driver.seq_item_port.connect(comp_sequencer.seq_item_export);
        
        uvm_info("AGENT", "Agent has connected sub-components", UVM_HIGH);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Scoreboard
//Evaluates the output of the DUT
class scoreboard: uvm_scoreboard
{
    mixin uvm_component_utils;

    this(string name, uvm_component parent = null) { super(name, parent); }

    @UVM_BUILD
    {
        //Building the analysis port to receive data from the Monitor
        //Add the class and function to which the port will send data
        uvm_analysis_imp!(scoreboard, write) mon_analysis_imp;
        //Imp is a final port i.e. it will not pass the data to another port
    }

    //override void build_phase(uvm_phase phase) {}

    void write(item comp)
    {
        //Reassigning varialble names for simplicity of coding
        uint a = comp.a, b = comp.b;

        //Printing expected values
        //uvm_info("SCOREBOARD", format("Expected: \n less_than = %d\n greater_than = %d\n equal_to = ", (a<b),(a>b),(a==b)), UVM_LOW);
        
        //Actual checking of output values by comparing with expected values
        if(comp.less_than == (a<b) && comp.greater_than == (a>b) && comp.equal_to == (a==b))
            uvm_info("MATCHED", "Comparison is Correct", UVM_LOW);
        else
            uvm_error("ERROR", "Comparison is Incorrect");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Enviroment
//Responsible for instantiating and connecting all testbench components
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

        uvm_info("ENVIRONMENT", "Environment is done building", UVM_HIGH);
    }

    override void connect_phase(uvm_phase phase)
    {
        super.connect_phase(phase);

        //Connecting the analysis port of the monitor to the analysis port in the scoreboard
        comp_agent.comp_monitor.mon_analysis_port.connect(comp_scoreboard.mon_analysis_imp);

        uvm_info("ENVIRONMENT", "Environment has connected sub-components", UVM_HIGH);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Test
//Instantiates an environment, sets up virtual interface handles for sub components and starts a top level sequence
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

        uvm_info("TEST", "Test is done building", UVM_HIGH);
        writeln("Test is done building");
    }
    
    override void run_phase(uvm_phase phase)
    {
        uvm_info("TEST", "Starting test", UVM_MEDIUM);
        
        //Set maximum duration for which the test will run
        phase.get_objection().set_drain_time(this, 200.nsec);

        //Object is created
        phase.raise_objection(this);

        seq comp_seq = seq.type_id.create("comp_seq");

        uvm_info("TEST", "Test has started", UVM_MEDIUM);
        
        //Sequence is randomized
        comp_seq.randomize();
        
        //Setting the path for the sequence to start: Environment -> Agent -> Sequencer
        comp_seq.start(comp_env.comp_agent.comp_sequencer);

        uvm_info("TEST", "Test is complete", UVM_MEDIUM);

        //Object is killed
        phase.drop_objection(this);
    }
}
*/

import Interface;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Top
//Top of testbench, actually starts the testbench and instantiates the design module
class Top: Entity
{
    import VMulti_Bit_Comparator_PowerGated_euvm;
    import esdl.intf.verilator.verilated;
    import std.stdio;

    VerilatedVcdD trace;
    DVMulti_Bit_Comparator_PowerGated dut;

    intf vif;

    //Clock is being driven from this class
    Signal!(ubvec!1) clock;

    //Opening Verilated trace
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

    //Closing Verilated trace
    void closetrace()
    {
        writeln("Closing trace");

        if(trace !is null)
        {
            trace.close();
            trace = null;

            writeln("Trace is closed");
        }
    }

    //Connecting the Interface to the Design 
    override void doConnect()
    {
        writeln("Connecting Interface to Design");
        
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
        
    
       // uvm_info("TOP", "Interface is connected to Design", UVM_HIGH);
        writeln("Interface is connected to Design");

    }

    //Building the verilated design file
    override void doBuild()
    {
        dut = new DVMulti_Bit_Comparator_PowerGated();
        traceEverOn(true);
        opentrace("Multi_Bit_Comparator_PowerGated.vcd");

        writeln("Test is built");
    }

    Task!stimulateClock stimulateClockTask;

    void stimulateClock()
    {
        clock = false;

        //Clock can be set to run for a fixed number of cycles
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
        writeln("Testbench started");

        //Connecting the driver and monitor to interface
        uvm_config_db!(intf).set(null, "uvm_test_top.comp_env.comp_agent.comp_driver", "vif", top.vif);
        uvm_config_db!(intf).set(null, "uvm_test_top.comp_env.comp_agent.comp_monitor", "vif", top.vif);
    
        uvm_info("TESTBENCH", "Tetsbench has been initialized", UVM_HIGH);
    }
}

//Main function that actually starts the testbench
void main(string[] args)
{
    import std.stdio;

    uint seed;

    CommandLine cmdl = new CommandLine(args);

    if(cmdl.plusArgs("seed = " ~ "%d", seed)) writeln("Using random seed: %d", seed);
    else seed = 1;

    auto tb = new testbench;

    tb.multicore(0, 1);
    writeln("Multicore works");

    tb.elaborate("tb", args);
    writeln("Elaborate works");

    tb.set_seed(seed);
    writeln("Seed works");

    tb.start();
    writeln("Testbench started");
}
