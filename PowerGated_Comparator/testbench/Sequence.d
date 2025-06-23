module Sequence;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Item;
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
    int n = 5;
    /** 
     * @rand int n; 
     Can be randomized also, fixed also
     It is randomized when applicable in multi-cycle designs, or data streams
     Example: FIFO, Avalon stream etc.
     

    constraint! q{
        n > 5;
        n < 10;
    } seq_constraint;
    */

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

            /** 
             * Cloning of item is not necessary
             It is useful when making a reference model
             Cloned item is sent to driver and Original is sent to scoreboard
             No reference model made here
             */
            item cloned = cast(item) comp.clone;
            send_request(cloned);
        }

        uvm_info("SEQ", format("%d ITEMS GENERATED", n), UVM_LOW);
    }
}
