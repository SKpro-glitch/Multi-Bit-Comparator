module Item;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
