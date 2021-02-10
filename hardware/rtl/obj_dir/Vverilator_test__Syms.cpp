// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vverilator_test__Syms.h"
#include "Vverilator_test.h"



// FUNCTIONS
Vverilator_test__Syms::~Vverilator_test__Syms()
{
}

Vverilator_test__Syms::Vverilator_test__Syms(Vverilator_test* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_verilator_test__top_instantiation__divider.configure(this, name(), "verilator_test.top_instantiation.divider", "divider", -9, VerilatedScope::SCOPE_OTHER);
}
