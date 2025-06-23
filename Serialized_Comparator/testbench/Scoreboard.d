module Scoreboard;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Item;

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
        //uvm_info("SCOREBOARD", format("Expected: \n less_than = ", (a<b), "\n greater_than = ", (a>b), "\n equal_to = ", (a==b)), UVM_LOW);
        
        //Actual checking of output values by comparing with expected values
        if(comp.less_than == (a<b) && comp.greater_than == (a>b) && comp.equal_to == (a==b))
            uvm_info("MATCHED", "Comparison is Correct", UVM_LOW);
        else
            uvm_error("ERROR", "Comparison is Incorrect");
    }
}
