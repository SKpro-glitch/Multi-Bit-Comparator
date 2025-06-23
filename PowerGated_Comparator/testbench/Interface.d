module Interface;

import esdl;
import esdl.intf.verilator.verilated;
import esdl.intf.verilator.trace;
import uvm;
import std.stdio;
import std.string: format;

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
