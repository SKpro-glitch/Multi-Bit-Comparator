import esdl.base.core: Entity;
import esdl.data.bvec: ubvec;
import esdl.intf.verilator.verilated: VerilatedContext, VerilatedModel, VlExport;
import esdl.intf.verilator.trace: VerilatedVcdC, VerilatedTraceBaseC,VerilatedVcdD;

//DESCRIPTION: Dlang code to link D classes and functions with the C++ classes


extern(C++) {
    align(8) class VSerialized_Comparator: VerilatedModel {
        //Symbol table, currently unimplemented, using void pointer
        void* vlSymsp;

        //PORTS 
        ubvec!(1)* clk;
        ubvec!(1)* reset;
        ubvec!(4)* a_in;
        ubvec!(4)* b_in;
        ubvec!(1)* less_than;
        ubvec!(1)* equal_to;
        ubvec!(1)* greater_than;

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
    VSerialized_Comparator create_VSerialized_Comparator();
    void finalize(VSerialized_Comparator obj);
    
}
class DVSerialized_Comparator: Entity
 {
    VSerialized_Comparator _dut;
    
    this () {
        _dut = create_VSerialized_Comparator();
    }
    override void doConnect() {
        clk(_dut.clk);
        reset(_dut.reset);
        a_in(_dut.a_in);
        b_in(_dut.b_in);
        less_than(_dut.less_than);
        equal_to(_dut.equal_to);
        greater_than(_dut.greater_than);
    }

    //Functions for Ports 
    VlExport!(1) clk;
    VlExport!(1) reset;
    VlExport!(4) a_in;
    VlExport!(4) b_in;
    VlExport!(1) less_than;
    VlExport!(1) equal_to;
    VlExport!(1) greater_than;
    final void eval() {
        _dut.eval();
    }
    final void finish() {
        finalize(_dut);
    }
    final void trace(VerilatedVcdD tfp, int levels, int options = 0) {
        _dut.trace(tfp.getTraceBase(), levels, options);
    }
    final void trace(VerilatedTraceBaseC tfp, int levels, int options = 0) {
        _dut.trace(tfp, levels, options);
    }
}
