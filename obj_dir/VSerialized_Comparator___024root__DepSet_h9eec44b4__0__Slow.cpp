// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSerialized_Comparator.h for the primary calling header

#include "VSerialized_Comparator__pch.h"
#include "VSerialized_Comparator___024root.h"

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_static__TOP(VSerialized_Comparator___024root* vlSelf);
VL_ATTR_COLD void VSerialized_Comparator___024root____Vm_traceActivitySetAll(VSerialized_Comparator___024root* vlSelf);

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_static(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSerialized_Comparator___024root___eval_static__TOP(vlSelf);
    VSerialized_Comparator___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_static__TOP(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Serialized_Comparator__DOT__start = 1U;
}

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_initial(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_final(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__stl(VSerialized_Comparator___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VSerialized_Comparator___024root___eval_phase__stl(VSerialized_Comparator___024root* vlSelf);

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_settle(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VSerialized_Comparator___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("Serialized_Comparator.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VSerialized_Comparator___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__stl(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSerialized_Comparator___024root___stl_sequent__TOP__0(VSerialized_Comparator___024root* vlSelf);

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_stl(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VSerialized_Comparator___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VSerialized_Comparator___024root___stl_sequent__TOP__0(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.solved = ((IData)(vlSelfRef.less_than) 
                        | ((IData)(vlSelfRef.equal_to) 
                           | (IData)(vlSelfRef.greater_than)));
}

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_triggers__stl(VSerialized_Comparator___024root* vlSelf);

VL_ATTR_COLD bool VSerialized_Comparator___024root___eval_phase__stl(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VSerialized_Comparator___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VSerialized_Comparator___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__act(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__nba(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSerialized_Comparator___024root____Vm_traceActivitySetAll(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VSerialized_Comparator___024root___ctor_var_reset(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->a_in = VL_RAND_RESET_I(4);
    vlSelf->b_in = VL_RAND_RESET_I(4);
    vlSelf->less_than = VL_RAND_RESET_I(1);
    vlSelf->equal_to = VL_RAND_RESET_I(1);
    vlSelf->greater_than = VL_RAND_RESET_I(1);
    vlSelf->solved = VL_RAND_RESET_I(1);
    vlSelf->Serialized_Comparator__DOT__a = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__b = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__c = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
