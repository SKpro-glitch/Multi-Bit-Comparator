module Environment;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Agent;
import Scoreboard;

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
