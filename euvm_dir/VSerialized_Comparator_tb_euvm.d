import esdl.base.core: Entity;
import esdl.data.bvec: ubvec;
import esdl.intf.verilator.verilated: VerilatedContext, VerilatedModel, VlExport;
import esdl.intf.verilator.trace: VerilatedVcdC, VerilatedTraceBaseC,VerilatedVcdD;

//DESCRIPTION: Dlang code to link D classes and functions with the C++ classes


extern(C++) {
    align(8) class VSerialized_Comparator_tb: VerilatedModel {
        //Symbol table, currently unimplemented, using void pointer
        void* vlSymsp;

        //PORTS 
        ubvec!(1)* clk;
        ubvec!(1)* reset;
        ubvec!(8)* a_in;
        ubvec!(8)* b_in;
        ubvec!(1)* less_than;
        ubvec!(1)* equal_to;
        ubvec!(1)* greater_than;
        ubvec!(1)* solved;
        
        // CELLS
        //Currently unimplemented, using void pointers 

        // Root instance pointer, currently unimplemented, using void pointers 
        void* rootp;
        this(VerilatedContext* contextp, const char* name = "TOP".ptr);
        ~this();
        final void eval();
        final void eval_step();
        final void eval_end_step();
        final void trace(VerilatedTraceBaseC tfp, int levels, int options = 0) {
              contextp().trace(tfp, levels, options);
        }
        final const(char*) name();
        final override char* hierName() const;
        final override char* modelName() const;
        final override uint threads() const;
    }
    VSerialized_Comparator_tb create_VSerialized_Comparator_tb();
    void finalize(VSerialized_Comparator_tb obj);
    
}

class DVSerialized_Comparator_tb: Entity
 {
    VSerialized_Comparator_tb dut;
    
    this () { dut = create_VSerialized_Comparator_tb(); }
    
    override void doConnect() {
        clk(dut.clk);
        reset(dut.reset);
        a_in(dut.a_in);
        b_in(dut.b_in);
        less_than(dut.less_than);
        equal_to(dut.equal_to);
        greater_than(dut.greater_than);
        solved(dut.solved);
    }

    //Functions for Ports 
    VlExport!(1) clk;
    VlExport!(1) reset;
    VlExport!(8) a_in;
    VlExport!(8) b_in;
    VlExport!(1) less_than;
    VlExport!(1) equal_to;
    VlExport!(1) greater_than;
    VlExport!(1) solved;

    final void eval() { dut.eval(); }

    final void finish() { finalize(dut); }

    final void trace(VerilatedVcdD tfp, int levels, int options = 0) 
    { dut.trace(tfp.getTraceBase(), levels, options); }

    final void trace(VerilatedTraceBaseC tfp, int levels, int options = 0) 
    { dut.trace(tfp, levels, options); }
}
