// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMulti_Bit_Comparator_Serialized.h for the primary calling header

#ifndef VERILATED_VMULTI_BIT_COMPARATOR_SERIALIZED___024ROOT_H_
#define VERILATED_VMULTI_BIT_COMPARATOR_SERIALIZED___024ROOT_H_  // guard

#include "verilated.h"


class VMulti_Bit_Comparator_Serialized__Syms;

class alignas(VL_CACHE_LINE_BYTES) VMulti_Bit_Comparator_Serialized___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(a_in,3,0);
    VL_IN8(b_in,3,0);
    VL_OUT8(less_than,0,0);
    VL_OUT8(equal_to,0,0);
    VL_OUT8(greater_than,0,0);
    CData/*3:0*/ Multi_Bit_Comparator__DOT__a;
    CData/*3:0*/ Multi_Bit_Comparator__DOT__b;
    CData/*3:0*/ Multi_Bit_Comparator__DOT__c;
    CData/*0:0*/ Multi_Bit_Comparator__DOT__start;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VMulti_Bit_Comparator_Serialized__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMulti_Bit_Comparator_Serialized___024root(VMulti_Bit_Comparator_Serialized__Syms* symsp, const char* v__name);
    ~VMulti_Bit_Comparator_Serialized___024root();
    VL_UNCOPYABLE(VMulti_Bit_Comparator_Serialized___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
