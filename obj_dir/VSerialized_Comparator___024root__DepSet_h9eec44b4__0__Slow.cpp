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

VL_ATTR_COLD void VSerialized_Comparator___024root___eval_settle(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
    vlSelf->Serialized_Comparator__DOT__a = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__b = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__c = VL_RAND_RESET_I(4);
    vlSelf->Serialized_Comparator__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
