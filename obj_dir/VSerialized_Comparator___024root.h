// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSerialized_Comparator.h for the primary calling header

#ifndef VERILATED_VSERIALIZED_COMPARATOR___024ROOT_H_
#define VERILATED_VSERIALIZED_COMPARATOR___024ROOT_H_  // guard

#include "verilated.h"


class VSerialized_Comparator__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSerialized_Comparator___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(a_in,3,0);
    VL_IN8(b_in,3,0);
    VL_OUT8(less_than,0,0);
    VL_OUT8(equal_to,0,0);
    VL_OUT8(greater_than,0,0);
    CData/*3:0*/ Serialized_Comparator__DOT__a;
    CData/*3:0*/ Serialized_Comparator__DOT__b;
    CData/*3:0*/ Serialized_Comparator__DOT__c;
    CData/*0:0*/ Serialized_Comparator__DOT__start;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSerialized_Comparator__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSerialized_Comparator___024root(VSerialized_Comparator__Syms* symsp, const char* v__name);
    ~VSerialized_Comparator___024root();
    VL_UNCOPYABLE(VSerialized_Comparator___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
