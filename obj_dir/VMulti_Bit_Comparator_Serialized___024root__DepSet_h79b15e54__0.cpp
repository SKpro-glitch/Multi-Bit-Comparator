// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMulti_Bit_Comparator_Serialized.h for the primary calling header

#include "VMulti_Bit_Comparator_Serialized__pch.h"
#include "VMulti_Bit_Comparator_Serialized___024root.h"

void VMulti_Bit_Comparator_Serialized___024root___eval_act(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VMulti_Bit_Comparator_Serialized___024root___nba_sequent__TOP__0(VMulti_Bit_Comparator_Serialized___024root* vlSelf);

void VMulti_Bit_Comparator_Serialized___024root___eval_nba(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VMulti_Bit_Comparator_Serialized___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VMulti_Bit_Comparator_Serialized___024root___nba_sequent__TOP__0(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.less_than = 0U;
        vlSelfRef.equal_to = 0U;
        vlSelfRef.greater_than = 0U;
        vlSelfRef.Multi_Bit_Comparator__DOT__start = 1U;
        vlSelfRef.Multi_Bit_Comparator__DOT__c = 0xfU;
    } else if (vlSelfRef.Multi_Bit_Comparator__DOT__start) {
        vlSelfRef.Multi_Bit_Comparator__DOT__a = vlSelfRef.a_in;
        vlSelfRef.Multi_Bit_Comparator__DOT__b = vlSelfRef.b_in;
        vlSelfRef.Multi_Bit_Comparator__DOT__start = 0U;
    }
    if (((IData)(vlSelfRef.equal_to) & (0U != (IData)(vlSelfRef.Multi_Bit_Comparator__DOT__c)))) {
        vlSelfRef.Multi_Bit_Comparator__DOT__c = (0xfU 
                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Multi_Bit_Comparator__DOT__c), 1U));
        if (vlSelfRef.reset) {
            vlSelfRef.less_than = 0U;
            vlSelfRef.equal_to = 0U;
            vlSelfRef.greater_than = 0U;
        } else if ((8U & ((IData)(vlSelfRef.Multi_Bit_Comparator__DOT__a) 
                          ^ (IData)(vlSelfRef.Multi_Bit_Comparator__DOT__b)))) {
            vlSelfRef.less_than = (1U & ((IData)(vlSelfRef.Multi_Bit_Comparator__DOT__b) 
                                         >> 3U));
            vlSelfRef.equal_to = 0U;
            vlSelfRef.greater_than = (1U & ((IData)(vlSelfRef.Multi_Bit_Comparator__DOT__a) 
                                            >> 3U));
        } else {
            vlSelfRef.less_than = 0U;
            vlSelfRef.equal_to = 1U;
            vlSelfRef.greater_than = 0U;
        }
        vlSelfRef.Multi_Bit_Comparator__DOT__a = (0xfU 
                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Multi_Bit_Comparator__DOT__a), 1U));
        vlSelfRef.Multi_Bit_Comparator__DOT__b = (0xfU 
                                                  & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.Multi_Bit_Comparator__DOT__b), 1U));
    }
}

void VMulti_Bit_Comparator_Serialized___024root___eval_triggers__act(VMulti_Bit_Comparator_Serialized___024root* vlSelf);

bool VMulti_Bit_Comparator_Serialized___024root___eval_phase__act(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VMulti_Bit_Comparator_Serialized___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VMulti_Bit_Comparator_Serialized___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VMulti_Bit_Comparator_Serialized___024root___eval_phase__nba(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VMulti_Bit_Comparator_Serialized___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMulti_Bit_Comparator_Serialized___024root___dump_triggers__nba(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VMulti_Bit_Comparator_Serialized___024root___dump_triggers__act(VMulti_Bit_Comparator_Serialized___024root* vlSelf);
#endif  // VL_DEBUG

void VMulti_Bit_Comparator_Serialized___024root___eval(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval\n"); );
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
            VMulti_Bit_Comparator_Serialized___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Multi_Bit_Comparator_Serialized.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VMulti_Bit_Comparator_Serialized___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Multi_Bit_Comparator_Serialized.v", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VMulti_Bit_Comparator_Serialized___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VMulti_Bit_Comparator_Serialized___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VMulti_Bit_Comparator_Serialized___024root___eval_debug_assertions(VMulti_Bit_Comparator_Serialized___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root___eval_debug_assertions\n"); );
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
