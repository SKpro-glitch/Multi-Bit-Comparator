module Driver;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

import Item;
import Interface;

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

            //Waiting one clock cycle before resetting again 
            wait(vif.clock.posedge());
            
            //Fetching an item and storing it in allocated memory
            seq_item_port.get_next_item(req);
            //The item 'req' is a built-in item which takes the value of the item originally passed as argument to the UVM class

            uvm_info(get_type_name(), "Got new item", UVM_MEDIUM);

            //Actual driving of them inputs
            //This can be written in another function and called also
            
            if(vif.solved)
            {
            //Design-specific requirement: The design must be reset before every new input
            vif.reset = true;

            //One clock cycle is needed for the reset to be evaluated
            wait(vif.clock.posedge());
            
            //Setting the active-high reset back to low and passing the inputs
            vif.reset = false;
            vif.a_in = req.a;
            vif.b_in = req.b;

            uvm_info("DRIVER", "Inputs have been provided", UVM_MEDIUM);
            
            //Declaring the item as done so that it can proceed to the next step
            seq_item_port.item_done();
            }
        }
    }
}
