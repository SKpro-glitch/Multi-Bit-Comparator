// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSerialized_Comparator__Syms.h"


VL_ATTR_COLD void VSerialized_Comparator___024root__trace_init_sub__TOP__0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+5,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+9,0,"less_than",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"equal_to",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"greater_than",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("Serialized_Comparator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+5,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+9,0,"less_than",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"equal_to",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"greater_than",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+2,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+3,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_init_top(VSerialized_Comparator___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSerialized_Comparator___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VSerialized_Comparator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSerialized_Comparator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSerialized_Comparator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_register(VSerialized_Comparator___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VSerialized_Comparator___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VSerialized_Comparator___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VSerialized_Comparator___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VSerialized_Comparator___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_const_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_const_0\n"); );
    // Init
    VSerialized_Comparator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSerialized_Comparator___024root*>(voidSelf);
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VSerialized_Comparator___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_const_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+12,(3U),32);
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_full_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_full_0\n"); );
    // Init
    VSerialized_Comparator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSerialized_Comparator___024root*>(voidSelf);
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VSerialized_Comparator___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VSerialized_Comparator___024root__trace_full_0_sub_0(VSerialized_Comparator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VSerialized_Comparator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSerialized_Comparator___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.Serialized_Comparator__DOT__a),4);
    bufp->fullCData(oldp+2,(vlSelfRef.Serialized_Comparator__DOT__b),4);
    bufp->fullCData(oldp+3,(vlSelfRef.Serialized_Comparator__DOT__c),4);
    bufp->fullBit(oldp+4,(vlSelfRef.Serialized_Comparator__DOT__start));
    bufp->fullBit(oldp+5,(vlSelfRef.clk));
    bufp->fullBit(oldp+6,(vlSelfRef.reset));
    bufp->fullCData(oldp+7,(vlSelfRef.a_in),4);
    bufp->fullCData(oldp+8,(vlSelfRef.b_in),4);
    bufp->fullBit(oldp+9,(vlSelfRef.less_than));
    bufp->fullBit(oldp+10,(vlSelfRef.equal_to));
    bufp->fullBit(oldp+11,(vlSelfRef.greater_than));
}
