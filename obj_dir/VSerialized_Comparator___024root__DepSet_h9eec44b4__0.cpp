// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSerialized_Comparator.h for the primary calling header

#include "VSerialized_Comparator__pch.h"
#include "VSerialized_Comparator___024root.h"

void VSerialized_Comparator___024root___eval_act(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VSerialized_Comparator___024root___nba_sequent__TOP__0(VSerialized_Comparator___024root* vlSelf);

void VSerialized_Comparator___024root___eval_nba(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VSerialized_Comparator___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VSerialized_Comparator___024root___nba_sequent__TOP__0(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.less_than = 0U;
        vlSelfRef.equal_to = 0U;
        vlSelfRef.greater_than = 0U;
        vlSelfRef.Serialized_Comparator__DOT__start = 1U;
        vlSelfRef.Serialized_Comparator__DOT__c = 0xfU;
    } else if (vlSelfRef.Serialized_Comparator__DOT__start) {
        vlSelfRef.Serialized_Comparator__DOT__a = vlSelfRef.a_in;
        vlSelfRef.Serialized_Comparator__DOT__b = vlSelfRef.b_in;
        vlSelfRef.Serialized_Comparator__DOT__start = 0U;
    }
    if (((IData)(vlSelfRef.equal_to) & (0U != (IData)(vlSelfRef.Serialized_Comparator__DOT__c)))) {
        vlSelfRef.Serialized_Comparator__DOT__c = (0xfU 
                                                   & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Serialized_Comparator__DOT__c), 1U));
        if (vlSelfRef.reset) {
            vlSelfRef.less_than = 0U;
            vlSelfRef.equal_to = 0U;
            vlSelfRef.greater_than = 0U;
        } else if ((8U & ((IData)(vlSelfRef.Serialized_Comparator__DOT__a) 
                          ^ (IData)(vlSelfRef.Serialized_Comparator__DOT__b)))) {
            vlSelfRef.less_than = (1U & ((IData)(vlSelfRef.Serialized_Comparator__DOT__b) 
                                         >> 3U));
            vlSelfRef.equal_to = 0U;
            vlSelfRef.greater_than = (1U & ((IData)(vlSelfRef.Serialized_Comparator__DOT__a) 
                                            >> 3U));
        } else {
            vlSelfRef.less_than = 0U;
            vlSelfRef.equal_to = 1U;
            vlSelfRef.greater_than = 0U;
        }
        vlSelfRef.Serialized_Comparator__DOT__a = (0xfU 
                                                   & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Serialized_Comparator__DOT__a), 1U));
        vlSelfRef.Serialized_Comparator__DOT__b = (0xfU 
                                                   & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Serialized_Comparator__DOT__b), 1U));
    }
}

void VSerialized_Comparator___024root___eval_triggers__act(VSerialized_Comparator___024root* vlSelf);

bool VSerialized_Comparator___024root___eval_phase__act(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VSerialized_Comparator___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VSerialized_Comparator___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VSerialized_Comparator___024root___eval_phase__nba(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VSerialized_Comparator___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__nba(VSerialized_Comparator___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VSerialized_Comparator___024root___dump_triggers__act(VSerialized_Comparator___024root* vlSelf);
#endif  // VL_DEBUG

void VSerialized_Comparator___024root___eval(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VSerialized_Comparator___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Serialized_Comparator.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VSerialized_Comparator___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Serialized_Comparator.v", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VSerialized_Comparator___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VSerialized_Comparator___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VSerialized_Comparator___024root___eval_debug_assertions(VSerialized_Comparator___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelfRef.a_in & 0xf0U))) {
        Verilated::overWidthError("a_in");}
    if (VL_UNLIKELY((vlSelfRef.b_in & 0xf0U))) {
        Verilated::overWidthError("b_in");}
}
#endif  // VL_DEBUG
