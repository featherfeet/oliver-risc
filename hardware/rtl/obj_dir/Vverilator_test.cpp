// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vverilator_test.h"
#include "Vverilator_test__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vverilator_test::Vverilator_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vverilator_test__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset_n{vlSymsp->TOP.reset_n}
    , verilator_only_dram_clk{vlSymsp->TOP.verilator_only_dram_clk}
    , verilator_only_vga_pixel_clock{vlSymsp->TOP.verilator_only_vga_pixel_clock}
    , rootp{&(vlSymsp->TOP)}
{
}

Vverilator_test::Vverilator_test(const char* _vcname__)
    : Vverilator_test(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vverilator_test::~Vverilator_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vverilator_test___024root___eval_initial(Vverilator_test___024root* vlSelf);
void Vverilator_test___024root___eval_settle(Vverilator_test___024root* vlSelf);
void Vverilator_test___024root___eval(Vverilator_test___024root* vlSelf);
#ifdef VL_DEBUG
void Vverilator_test___024root___eval_debug_assertions(Vverilator_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vverilator_test___024root___final(Vverilator_test___024root* vlSelf);

static void _eval_initial_loop(Vverilator_test__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vverilator_test___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vverilator_test___024root___eval_settle(&(vlSymsp->TOP));
        Vverilator_test___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vverilator_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vverilator_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vverilator_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vverilator_test___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

void Vverilator_test::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vverilator_test::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Invoke final blocks

void Vverilator_test::final() {
    Vverilator_test___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vverilator_test::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vverilator_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vverilator_test___024root__trace_init_top(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep);

static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vverilator_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_test___024root*>(voidSelf);
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vverilator_test___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vverilator_test___024root__trace_register(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep);

void Vverilator_test::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vverilator_test___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
