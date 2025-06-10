// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMulti_Bit_Comparator_Serialized__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VMulti_Bit_Comparator_Serialized::VMulti_Bit_Comparator_Serialized(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMulti_Bit_Comparator_Serialized__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , less_than{vlSymsp->TOP.less_than}
    , equal_to{vlSymsp->TOP.equal_to}
    , greater_than{vlSymsp->TOP.greater_than}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VMulti_Bit_Comparator_Serialized::VMulti_Bit_Comparator_Serialized(const char* _vcname__)
    : VMulti_Bit_Comparator_Serialized(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMulti_Bit_Comparator_Serialized::~VMulti_Bit_Comparator_Serialized() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMulti_Bit_Comparator_Serialized___024root___eval_debug_assertions(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
#endif  // VL_DEBUG
void VMulti_Bit_Comparator_Serialized___024root___eval_static(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
void VMulti_Bit_Comparator_Serialized___024root___eval_initial(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
void VMulti_Bit_Comparator_Serialized___024root___eval_settle(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
void VMulti_Bit_Comparator_Serialized___024root___eval(VMulti_Bit_Comparator_Serialized___024root* vlSelf);

void VMulti_Bit_Comparator_Serialized::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMulti_Bit_Comparator_Serialized::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMulti_Bit_Comparator_Serialized___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMulti_Bit_Comparator_Serialized___024root___eval_static(&(vlSymsp->TOP));
        VMulti_Bit_Comparator_Serialized___024root___eval_initial(&(vlSymsp->TOP));
        VMulti_Bit_Comparator_Serialized___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMulti_Bit_Comparator_Serialized___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMulti_Bit_Comparator_Serialized::eventsPending() { return false; }

uint64_t VMulti_Bit_Comparator_Serialized::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMulti_Bit_Comparator_Serialized::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMulti_Bit_Comparator_Serialized___024root___eval_final(VMulti_Bit_Comparator_Serialized___024root* vlSelf);

VL_ATTR_COLD void VMulti_Bit_Comparator_Serialized::final() {
    VMulti_Bit_Comparator_Serialized___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMulti_Bit_Comparator_Serialized::hierName() const { return vlSymsp->name(); }
const char* VMulti_Bit_Comparator_Serialized::modelName() const { return "VMulti_Bit_Comparator_Serialized"; }
unsigned VMulti_Bit_Comparator_Serialized::threads() const { return 1; }
void VMulti_Bit_Comparator_Serialized::prepareClone() const { contextp()->prepareClone(); }
void VMulti_Bit_Comparator_Serialized::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VMulti_Bit_Comparator_Serialized::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VMulti_Bit_Comparator_Serialized___024root__trace_decl_types(VerilatedVcd* tracep);

void VMulti_Bit_Comparator_Serialized___024root__trace_init_top(VMulti_Bit_Comparator_Serialized___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VMulti_Bit_Comparator_Serialized___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMulti_Bit_Comparator_Serialized___024root*>(voidSelf);
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VMulti_Bit_Comparator_Serialized___024root__trace_decl_types(tracep);
    VMulti_Bit_Comparator_Serialized___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VMulti_Bit_Comparator_Serialized___024root__trace_register(VMulti_Bit_Comparator_Serialized___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VMulti_Bit_Comparator_Serialized::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VMulti_Bit_Comparator_Serialized::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VMulti_Bit_Comparator_Serialized___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
