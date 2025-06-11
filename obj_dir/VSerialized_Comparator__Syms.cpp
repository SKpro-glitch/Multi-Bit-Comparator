// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VSerialized_Comparator__pch.h"
#include "VSerialized_Comparator.h"
#include "VSerialized_Comparator___024root.h"

// FUNCTIONS
VSerialized_Comparator__Syms::~VSerialized_Comparator__Syms()
{
}

VSerialized_Comparator__Syms::VSerialized_Comparator__Syms(VerilatedContext* contextp, const char* namep, VSerialized_Comparator* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(11);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
