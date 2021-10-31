// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_test.h for the primary calling header

#include "verilated.h"

#include "Vverilator_test__Syms.h"
#include "Vverilator_test___024root.h"

void Vverilator_test___024root___ctor_var_reset(Vverilator_test___024root* vlSelf);

Vverilator_test___024root::Vverilator_test___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vverilator_test___024root___ctor_var_reset(this);
}

void Vverilator_test___024root::__Vconfigure(Vverilator_test__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vverilator_test___024root::~Vverilator_test___024root() {
}
