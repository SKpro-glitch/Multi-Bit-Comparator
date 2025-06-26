import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Interface;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Top
//Top of testbench, actually starts the testbench and instantiates the design module
class Top: Entity
{
    import VSerialized_Comparator_euvm;
    import esdl.intf.verilator.verilated;
    import std.stdio;

    VerilatedVcdD trace;
    DVSerialized_Comparator dut;

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
    
        //uvm_info("TOP", "Interface is connected to Design", UVM_HIGH);
    }

    //Building the verilated design file
    override void doBuild()
    {
        dut = new DVSerialized_Comparator();
        traceEverOn(true);
        opentrace("Serialized_Comparator.vcd");
    }

    Task!stimulateClock stimulateClockTask;

    void stimulateClock()
    {
        clock = false;

        //Clock can be set to run for a fixed number of cycles
        //for(size_t i=0; i<50; i++)
        while(true)
        {
            clock = false;
            dut.clock = false;

            wait(10.nsec);
            dut.eval();
            if(trace !is null) trace.dump(getSimTime().getVal());

            clock = true;
            dut.clock = true;
            wait(10.nsec);
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
    tb.elaborate("tb", args);
    tb.set_seed(seed);
    tb.start();
}