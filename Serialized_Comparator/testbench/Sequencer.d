module Sequencer;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Item;
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
