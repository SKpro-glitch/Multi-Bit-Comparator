// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSerialized_Comparator__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSerialized_Comparator::VSerialized_Comparator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSerialized_Comparator__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , less_than{vlSymsp->TOP.less_than}
    , equal_to{vlSymsp->TOP.equal_to}
    , greater_than{vlSymsp->TOP.greater_than}
    , solved{vlSymsp->TOP.solved}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VSerialized_Comparator::VSerialized_Comparator(const char* _vcname__)
    : VSerialized_Comparator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSerialized_Comparator::~VSerialized_Comparator() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSerialized_Comparator___024root___eval_debug_assertions(VSerialized_Comparator___024root* vlSelf);
#endif  // VL_DEBUG
void VSerialized_Comparator___024root___eval_static(VSerialized_Comparator___024root* vlSelf);
void VSerialized_Comparator___024root___eval_initial(VSerialized_Comparator___024root* vlSelf);
void VSerialized_Comparator___024root___eval_settle(VSerialized_Comparator___024root* vlSelf);
void VSerialized_Comparator___024root___eval(VSerialized_Comparator___024root* vlSelf);

void VSerialized_Comparator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSerialized_Comparator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSerialized_Comparator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSerialized_Comparator___024root___eval_static(&(vlSymsp->TOP));
        VSerialized_Comparator___024root___eval_initial(&(vlSymsp->TOP));
        VSerialized_Comparator___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSerialized_Comparator___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSerialized_Comparator::eventsPending() { return false; }

uint64_t VSerialized_Comparator::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSerialized_Comparator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSerialized_Comparator___024root___eval_final(VSerialized_Comparator___024root* vlSelf);

VL_ATTR_COLD void VSerialized_Comparator::final() {
    VSerialized_Comparator___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSerialized_Comparator::hierName() const { return vlSymsp->name(); }
const char* VSerialized_Comparator::modelName() const { return "VSerialized_Comparator"; }
unsigned VSerialized_Comparator::threads() const { return 1; }
void VSerialized_Comparator::prepareClone() const { contextp()->prepareClone(); }
void VSerialized_Comparator::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VSerialized_Comparator::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VSerialized_Comparator___024root__trace_decl_types(VerilatedVcd* tracep);

void VSerialized_Comparator___024root__trace_init_top(VSerialized_Comparator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSerialized_Comparator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSerialized_Comparator___024root*>(voidSelf);
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VSerialized_Comparator___024root__trace_decl_types(tracep);
    VSerialized_Comparator___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_register(VSerialized_Comparator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSerialized_Comparator::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VSerialized_Comparator::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSerialized_Comparator___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
