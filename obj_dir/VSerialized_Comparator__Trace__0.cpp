// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSerialized_Comparator__Syms.h"


void VSerialized_Comparator___024root__trace_chg_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VSerialized_Comparator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_chg_0\n"); );
    // Init
    VSerialized_Comparator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSerialized_Comparator___024root*>(voidSelf);
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VSerialized_Comparator___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VSerialized_Comparator___024root__trace_chg_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.Serialized_Comparator__DOT__a),4);
        bufp->chgCData(oldp+1,(vlSelfRef.Serialized_Comparator__DOT__b),4);
        bufp->chgCData(oldp+2,(vlSelfRef.Serialized_Comparator__DOT__c),4);
        bufp->chgBit(oldp+3,(vlSelfRef.Serialized_Comparator__DOT__start));
    }
    bufp->chgBit(oldp+4,(vlSelfRef.clk));
    bufp->chgBit(oldp+5,(vlSelfRef.reset));
    bufp->chgCData(oldp+6,(vlSelfRef.a_in),4);
    bufp->chgCData(oldp+7,(vlSelfRef.b_in),4);
    bufp->chgBit(oldp+8,(vlSelfRef.less_than));
    bufp->chgBit(oldp+9,(vlSelfRef.equal_to));
    bufp->chgBit(oldp+10,(vlSelfRef.greater_than));
    bufp->chgBit(oldp+11,(vlSelfRef.solved));
}

void VSerialized_Comparator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_cleanup\n"); );
    // Init
    VSerialized_Comparator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSerialized_Comparator___024root*>(voidSelf);
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
