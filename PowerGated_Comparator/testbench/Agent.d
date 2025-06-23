module Agent;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Driver;
import Monitor;
import Sequencer;
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
