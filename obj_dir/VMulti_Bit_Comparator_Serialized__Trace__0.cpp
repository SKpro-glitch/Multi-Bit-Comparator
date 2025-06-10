// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMulti_Bit_Comparator_Serialized__Syms.h"


void VMulti_Bit_Comparator_Serialized___024root__trace_chg_0_sub_0(VMulti_Bit_Comparator_Serialized___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VMulti_Bit_Comparator_Serialized___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root__trace_chg_0\n"); );
    // Init
    VMulti_Bit_Comparator_Serialized___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMulti_Bit_Comparator_Serialized___024root*>(voidSelf);
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VMulti_Bit_Comparator_Serialized___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VMulti_Bit_Comparator_Serialized___024root__trace_chg_0_sub_0(VMulti_Bit_Comparator_Serialized___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.Multi_Bit_Comparator__DOT__a),4);
        bufp->chgCData(oldp+1,(vlSelfRef.Multi_Bit_Comparator__DOT__b),4);
        bufp->chgCData(oldp+2,(vlSelfRef.Multi_Bit_Comparator__DOT__c),4);
        bufp->chgBit(oldp+3,(vlSelfRef.Multi_Bit_Comparator__DOT__start));
    }
    bufp->chgBit(oldp+4,(vlSelfRef.clk));
    bufp->chgBit(oldp+5,(vlSelfRef.reset));
    bufp->chgCData(oldp+6,(vlSelfRef.a_in),4);
    bufp->chgCData(oldp+7,(vlSelfRef.b_in),4);
    bufp->chgBit(oldp+8,(vlSelfRef.less_than));
    bufp->chgBit(oldp+9,(vlSelfRef.equal_to));
    bufp->chgBit(oldp+10,(vlSelfRef.greater_than));
}

void VMulti_Bit_Comparator_Serialized___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMulti_Bit_Comparator_Serialized___024root__trace_cleanup\n"); );
    // Init
    VMulti_Bit_Comparator_Serialized___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMulti_Bit_Comparator_Serialized___024root*>(voidSelf);
    VMulti_Bit_Comparator_Serialized__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
