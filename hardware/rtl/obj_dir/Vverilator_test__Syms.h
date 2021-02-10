// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VVERILATOR_TEST__SYMS_H_
#define _VVERILATOR_TEST__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vverilator_test.h"

// SYMS CLASS
class Vverilator_test__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vverilator_test*               TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_verilator_test__top_instantiation__divider;
    
    // CREATORS
    Vverilator_test__Syms(Vverilator_test* topp, const char* namep);
    ~Vverilator_test__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
