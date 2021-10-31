// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVERILATOR_TEST__SYMS_H_
#define VERILATED_VVERILATOR_TEST__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vverilator_test.h"

// INCLUDE MODULE CLASSES
#include "Vverilator_test___024root.h"

// SYMS CLASS (contains all model state)
class Vverilator_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vverilator_test* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vverilator_test___024root      TOP;

    // CONSTRUCTORS
    Vverilator_test__Syms(VerilatedContext* contextp, const char* namep, Vverilator_test* modelp);
    ~Vverilator_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
