import esdl;
import uvm;

import std.stdio;

void main(string[] args)
{

}

class Top: Entity
{
    Signal!(ubvec!1) reset;
    Signal!(ubvec!1) clock;

    Comp_in_intf comp_in;
    Comp_out_intf compt_out;

    override void doConnect()
    {
        //Connecting th einputs ports to the interface
        comp_in.clock(clock);
        comp_in.reset(reset);
        
        comp_in.a_in(dut.a_in);
        comp_in.b_in(dut.b_in);

    }
}

class Comp_in_intf: VlInterface
{
    Port!(Signal!(ubvec!1)) reset;
    Port!(Signal!(ubvec!1)) clock;

    VlPort!4 a_in, b_in;
}

class Comp_out_intf: VlInterface
{
    Port!(Signal!(ubvec!1)) reset;
    Port!(Signal!(ubvec!1)) clock;

    VlPort!1 less_than, equal_to, greater_than;
}

