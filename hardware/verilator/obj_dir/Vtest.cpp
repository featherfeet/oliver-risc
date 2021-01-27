// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest.h for the primary calling header

#include "Vtest.h"
#include "Vtest__Syms.h"

//==========

void Vtest::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest::eval\n"); );
    Vtest__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("test.v", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtest::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtest::eval_end_step\n"); );
#ifdef VM_TRACE
    Vtest__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) _traceDump();
#endif  // VM_TRACE
}

void Vtest::_eval_initial_loop(Vtest__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("test.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtest::_sequent__TOP__2(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__2\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__state;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v0;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_write_state;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_read_state;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__operation;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v1;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v2;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v3;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v3;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v4;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v4;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v5;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v6;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v6;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v7;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v8;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v9;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v9;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v10;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v11;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v11;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v12;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v14;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v16;
    CData/*4:0*/ __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v18;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v19;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v20;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v21;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v22;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v23;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v23;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v24;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v25;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v25;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v26;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v27;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v27;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v28;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v29;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v31;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v32;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v33;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v34;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v36;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v38;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v40;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v40;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v41;
    CData/*2:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    CData/*1:0*/ __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v43;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v44;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v46;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v52;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v53;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v54;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v55;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v56;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v57;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v58;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v59;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v60;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v61;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v62;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v1;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v2;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v3;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v4;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v5;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v6;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v7;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v8;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v9;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v64;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v65;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v66;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1;
    CData/*3:0*/ __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    CData/*3:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1;
    CData/*3:0*/ __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    CData/*2:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*7:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__gpu_character_read;
    CData/*4:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    CData/*4:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    SData/*15:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data;
    SData/*15:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data;
    SData/*15:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data;
    SData/*15:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data;
    SData/*15:0*/ __Vdly__test__DOT__top_instantiation__DOT__ram_read_data;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address;
    IData/*21:0*/ __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v0;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__program_rom_address;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__operand1;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__operand2;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v1;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v2;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v3;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v4;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v5;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__temp_address;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v6;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v7;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v8;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v9;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v10;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v11;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v12;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v13;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v14;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v15;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v16;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v17;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v18;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v19;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v20;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v21;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v22;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v23;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v24;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v25;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v26;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v27;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v28;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v29;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v30;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v31;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v32;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v33;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v34;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v35;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v36;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v37;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v38;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v39;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v40;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v41;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v42;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v43;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v44;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v52;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v53;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v54;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v55;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v56;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v57;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v58;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v59;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v60;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v61;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v63;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v1;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v2;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v3;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v4;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v5;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v6;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v7;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v8;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v9;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    IData/*31:0*/ __Vdly__test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    // Body
    __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
        = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    __Vdly__test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1 = 0U;
    __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read 
        = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read 
        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read 
        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__gpu_access_state;
    __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter 
        = vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter;
    __Vdly__test__DOT__top_instantiation__DOT__temp_address 
        = vlTOPp->test__DOT__top_instantiation__DOT__temp_address;
    __Vdly__test__DOT__top_instantiation__DOT__operand2 
        = vlTOPp->test__DOT__top_instantiation__DOT__operand2;
    __Vdly__test__DOT__top_instantiation__DOT__operand1 
        = vlTOPp->test__DOT__top_instantiation__DOT__operand1;
    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
        = vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index;
    __Vdly__test__DOT__top_instantiation__DOT__operation 
        = vlTOPp->test__DOT__top_instantiation__DOT__operation;
    __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete;
    __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data;
    __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state;
    __Vdly__test__DOT__top_instantiation__DOT__ram_write_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state;
    __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete;
    __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address 
        = vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address;
    __Vdly__test__DOT__top_instantiation__DOT__ram_stabilization_counter 
        = vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    __Vdly__test__DOT__top_instantiation__DOT__state 
        = vlTOPp->test__DOT__top_instantiation__DOT__state;
    __Vdly__test__DOT__top_instantiation__DOT__program_rom_address 
        = vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address;
    __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 = 0U;
    __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    __Vdly__test__DOT__top_instantiation__DOT__gpu_character_read 
        = vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_read;
    vlTOPp->__Vdlyvset__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v1 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v2 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v3 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v4 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v5 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v6 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v7 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v8 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v9 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v0 = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__i = 0xaU;
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__i = 0xaU;
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__i = 5U;
    }
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v0 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v1 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v2 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v3 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v4 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v5 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v6 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v7 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v8 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v9 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v10 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v11 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v12 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v14 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v16 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v18 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v19 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v20 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v21 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v22 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v23 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v24 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v25 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v26 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v27 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v28 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v29 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v31 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v32 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v33 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v34 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v36 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v38 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v40 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v41 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v43 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v44 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v46 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v52 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v53 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v54 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v55 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v56 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v57 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v58 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v59 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v60 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v61 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v62 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v64 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v65 = 0U;
    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v66 = 0U;
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_ready) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full)))) {
            __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
                = (7U & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty)))) {
            __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
                = (7U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size) 
                         - (IData)(1U)));
        }
    } else {
        __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound5 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient;
    if (VL_LIKELY((0x10U >= (0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)))) {
        __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 
            = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound5;
        __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 = 1U;
        __Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 
            = (0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr);
    }
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound6 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain;
    if (VL_LIKELY((0x10U >= (0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)))) {
        __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 
            = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound6;
        __Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 = 1U;
        __Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 
            = (0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr);
    }
    __Vdly__test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = VL_MODDIVS_III(32, ((IData)(1U) + vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr), (IData)(0xfU));
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_ready) 
             & (~ ((5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound2 
                = (0xffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register));
            if ((4U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))) {
                __Vdlyvval__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound2;
                __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer;
            }
            vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer 
                = ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1 = 1U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full)))) {
            __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_read) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty)))) {
            __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size = 0U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_full)))) {
            __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_read) 
             & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_empty)))) {
            __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size = 0U;
    }
    __Vdly__test__DOT__top_instantiation__DOT__gpu_character_read 
        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable)
            ? (IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_to_write)
            : ((0x3ecfU >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access))
                ? vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer
               [vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access]
                : 0U));
    if (vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable) {
        vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound1 
            = vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_to_write;
        if ((0x3ecfU >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access))) {
            vlTOPp->__Vdlyvval__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 
                = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound1;
            vlTOPp->__Vdlyvset__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 1U;
            vlTOPp->__Vdlyvdim0__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 
                = vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access;
        }
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write) 
             & (~ ((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound2 
                = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in;
            if ((9U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))) {
                __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound2;
                __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer;
            }
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer 
                = ((9U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1 = 1U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write) 
             & (~ ((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound2 
                = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_in;
            if ((9U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))) {
                __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound2;
                __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 
                    = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer;
            }
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer 
                = ((9U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1 = 1U;
    }
    if (vlTOPp->reset) {
        if (((((((((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state)) 
                   | (1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
                  | (2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
                 | (3U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
                | (4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
               | (5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
              | (6U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) 
             | (7U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state)))) {
            if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                if (VL_UNLIKELY(((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done) 
                                 & (0x14U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter))))) {
                    VL_WRITEF("%t: Changing state to STATE_LOAD_TO_RAM\n",
                              64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))));
                    __Vdly__test__DOT__top_instantiation__DOT__state = 1U;
                } else {
                    if (VL_UNLIKELY(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done)) {
                        __Vdly__test__DOT__top_instantiation__DOT__ram_stabilization_counter 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter)));
                        VL_WRITEF("%t: Init_done is done. Counter is %3#.\n",
                                  64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))),
                                  8,(IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter));
                    } else {
                        __Vdly__test__DOT__top_instantiation__DOT__state = 0U;
                    }
                }
            } else {
                if ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                    if (VL_UNLIKELY(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_done)) {
                        VL_WRITEF("%t: Changing state to STATE_FETCH_OPERATION\n",
                                  64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))));
                        __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address 
                            = ((IData)(4U) + vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address);
                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                        vlTOPp->test__DOT__top_instantiation__DOT__program_end_address 
                            = vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address;
                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v0 
                            = ((IData)(4U) + vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address);
                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v0 = 1U;
                        __Vdly__test__DOT__top_instantiation__DOT__state = 2U;
                    } else {
                        if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_read_state))))) {
                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data 
                                = vlTOPp->test__DOT__top_instantiation__DOT__program_rom_byte;
                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address 
                                = (0x3fffffU & vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address);
                            VL_WRITEF("program_rom_address: %10#\n",
                                      32,vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address);
                            if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state 
                                    = ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else {
                                if ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                        = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address;
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                        = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data;
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                    __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                                } else {
                                    if ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                                    }
                                }
                            }
                            VL_WRITEF("program_rom_byte: %3#\n",
                                      8,vlTOPp->test__DOT__top_instantiation__DOT__program_rom_byte);
                        }
                        if (vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete) {
                            if ((4U > vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address)) {
                                __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address 
                                    = (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_byte) 
                                        << 0x18U) | 
                                       (0xffffffU & 
                                        (vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
                                         >> 8U)));
                            }
                            __Vdly__test__DOT__top_instantiation__DOT__program_rom_address 
                                = ((IData)(1U) + vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address);
                            vlTOPp->test__DOT__top_instantiation__DOT__program_rom_read_state = 1U;
                        } else {
                            vlTOPp->test__DOT__top_instantiation__DOT__program_rom_read_state = 0U;
                        }
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                        __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address 
                            = (0x3fffffU & vlTOPp->test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
                            __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                = ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                    ? 0U : 1U);
                        } else {
                            if ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                            } else {
                                if ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                            = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                    }
                                }
                            }
                        }
                        if (vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete) {
                            __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                            __Vdly__test__DOT__top_instantiation__DOT__operation 
                                = (0xffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data));
                            __Vdly__test__DOT__top_instantiation__DOT__state = 3U;
                        } else {
                            __Vdly__test__DOT__top_instantiation__DOT__state = 2U;
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                            if ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))) {
                                __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                __Vdly__test__DOT__top_instantiation__DOT__state = 4U;
                            } else {
                                if (vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete) {
                                    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                    __Vdly__test__DOT__top_instantiation__DOT__operand1 
                                        = ((0xff000000U 
                                            & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data) 
                                               << 0x18U)) 
                                           | (0xffffffU 
                                              & (vlTOPp->test__DOT__top_instantiation__DOT__operand1 
                                                 >> 8U)));
                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                                } else {
                                    __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address 
                                        = (0x3fffffU 
                                           & ((IData)(1U) 
                                              + (vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                 [0U] 
                                                 + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))));
                                    if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                            = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                            = ((2U 
                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                ? 0U
                                                : 1U);
                                    } else {
                                        if ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                            __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                                        } else {
                                            if ((2U 
                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                                if ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))) {
                                    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                    __Vdly__test__DOT__top_instantiation__DOT__state = 5U;
                                } else {
                                    if (vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete) {
                                        __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                        __Vdly__test__DOT__top_instantiation__DOT__operand2 
                                            = ((0xff000000U 
                                                & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data) 
                                                   << 0x18U)) 
                                               | (0xffffffU 
                                                  & (vlTOPp->test__DOT__top_instantiation__DOT__operand2 
                                                     >> 8U)));
                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                                    } else {
                                        __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address 
                                            = (0x3fffffU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                   [0U] 
                                                   + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))));
                                        if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
                                            __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                                = (
                                                   (2U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                    ? 0U
                                                    : 1U);
                                        } else {
                                            if ((1U 
                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                    = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                                            } else {
                                                if (
                                                    (2U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                                    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if ((5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                                    if (((((((((0U 
                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                              | (0x11U 
                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                             | (0x13U 
                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                            | (2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                           | (0x12U 
                                              == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                          | (3U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                         | (4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                        if (VL_UNLIKELY(
                                                        (0U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                            VL_WRITEF("NOP\n");
                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v1 
                                                = ((IData)(9U) 
                                                   + 
                                                   vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                   [0U]);
                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v1 = 1U;
                                            __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                        } else {
                                            if ((1U 
                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                if (VL_UNLIKELY(
                                                                (4U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                                                    VL_WRITEF("LOAD\nLoaded value %0# from address %0# in RAM to register %0#.\n",
                                                              32,
                                                              ((9U 
                                                                >= 
                                                                (0xfU 
                                                                 & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                ? 
                                                               vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                               [
                                                               (0xfU 
                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                : 0U),
                                                              32,
                                                              vlTOPp->test__DOT__top_instantiation__DOT__operand1,
                                                              32,
                                                              vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v2 
                                                        = 
                                                        ((IData)(9U) 
                                                         + 
                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                         [0U]);
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v2 = 1U;
                                                } else {
                                                    if (vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete) {
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound1 
                                                            = 
                                                            ((0xff000000U 
                                                              & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data) 
                                                                 << 0x18U)) 
                                                             | (0xffffffU 
                                                                & (((9U 
                                                                     >= 
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                     ? 
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                    [
                                                                    (0xfU 
                                                                     & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                     : 0U) 
                                                                   >> 8U)));
                                                        __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                                                        if (
                                                            (9U 
                                                             >= 
                                                             (0xfU 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v3 
                                                                = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound1;
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v3 = 1U;
                                                            __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v3 
                                                                = 
                                                                (0xfU 
                                                                 & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                        }
                                                    } else {
                                                        __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address 
                                                            = 
                                                            (0x3fffffU 
                                                             & (vlTOPp->test__DOT__top_instantiation__DOT__operand1 
                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                        if (
                                                            (0U 
                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
                                                            __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                                                = 
                                                                ((2U 
                                                                  == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                  ? 0U
                                                                  : 1U);
                                                        } else {
                                                            if (
                                                                (1U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                    = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                                                            } else {
                                                                if (
                                                                    (2U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                                                    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                                                            = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (
                                                    (0x11U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                    if (vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete) {
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound2 
                                                            = 
                                                            ((0xff000000U 
                                                              & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data) 
                                                                 << 0x18U)) 
                                                             | (0xffffffU 
                                                                & (((9U 
                                                                     >= 
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                     ? 
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                    [
                                                                    (0xfU 
                                                                     & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                     : 0U) 
                                                                   >> 8U)));
                                                        __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                                                        if (
                                                            (9U 
                                                             >= 
                                                             (0xfU 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v4 
                                                                = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound2;
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v4 = 1U;
                                                            __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v4 
                                                                = 
                                                                (0xfU 
                                                                 & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                        }
                                                    } else {
                                                        if (VL_UNLIKELY(
                                                                        (4U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                                                            VL_WRITEF("RLOAD\nLoaded value %0# from address %0# in RAM to register %0#.\n",
                                                                      32,
                                                                      ((9U 
                                                                        >= 
                                                                        (0xfU 
                                                                         & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                        ? 
                                                                       vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                       [
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                        : 0U),
                                                                      32,
                                                                      vlTOPp->test__DOT__top_instantiation__DOT__temp_address,
                                                                      32,
                                                                      vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                            __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                                            __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v5 
                                                                = 
                                                                ((IData)(9U) 
                                                                 + 
                                                                 vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                 [0U]);
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v5 = 1U;
                                                        } else {
                                                            if (
                                                                (0U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))) {
                                                                __Vdly__test__DOT__top_instantiation__DOT__temp_address 
                                                                    = 
                                                                    ((9U 
                                                                      >= 
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                      ? 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                      : 0U);
                                                                __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address 
                                                                    = 
                                                                    (0x3fffffU 
                                                                     & (((9U 
                                                                          >= 
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                          ? 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [
                                                                         (0xfU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                          : 0U) 
                                                                        + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                if (
                                                                    (0U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                        = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                                                        = 
                                                                        ((2U 
                                                                          == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                          ? 0U
                                                                          : 1U);
                                                                } else {
                                                                    if (
                                                                        (1U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                            = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                                                                    } else {
                                                                        if (
                                                                            (2U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                                                            if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                                                                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address 
                                                                    = 
                                                                    (0x3fffffU 
                                                                     & (vlTOPp->test__DOT__top_instantiation__DOT__temp_address 
                                                                        + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                if (
                                                                    (0U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                        = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_read_state 
                                                                        = 
                                                                        ((2U 
                                                                          == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                          ? 0U
                                                                          : 1U);
                                                                } else {
                                                                    if (
                                                                        (1U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                            = __Vtask_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                                                                    } else {
                                                                        if (
                                                                            (2U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state))) {
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                                                            if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_read_data 
                                                                                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (VL_UNLIKELY(
                                                                    (0x13U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                        VL_WRITEF("CLOAD\n");
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound3 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT__operand1;
                                                        if (
                                                            (9U 
                                                             >= 
                                                             (0xfU 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v6 
                                                                = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound3;
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v6 = 1U;
                                                            __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v6 
                                                                = 
                                                                (0xfU 
                                                                 & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                        }
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v7 
                                                            = 
                                                            ((IData)(9U) 
                                                             + 
                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                             [0U]);
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v7 = 1U;
                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                    } else {
                                                        if (
                                                            (2U 
                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                            if (VL_UNLIKELY(
                                                                            (4U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                                                                VL_WRITEF("STORE\n");
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v8 
                                                                    = 
                                                                    ((IData)(9U) 
                                                                     + 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [0U]);
                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v8 = 1U;
                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            } else {
                                                                if (vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete) {
                                                                    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(1U) 
                                                                            + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound4 
                                                                        = 
                                                                        ((((9U 
                                                                            >= 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                            ? 
                                                                           (0xffU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                            [
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                            : 0U) 
                                                                          << 0x18U) 
                                                                         | (0xffffffU 
                                                                            & (((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                 : 0U) 
                                                                               >> 8U)));
                                                                    if (
                                                                        (9U 
                                                                         >= 
                                                                         (0xfU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__operand1))) {
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v9 
                                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound4;
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v9 = 1U;
                                                                        __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v9 
                                                                            = 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1);
                                                                    }
                                                                    __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                                                } else {
                                                                    __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data 
                                                                        = 
                                                                        ((9U 
                                                                          >= 
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                          ? 
                                                                         (0xffU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                          : 0U);
                                                                    __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address 
                                                                        = 
                                                                        (0x3fffffU 
                                                                         & (vlTOPp->test__DOT__top_instantiation__DOT__operand2 
                                                                            + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                    if (
                                                                        (0U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_write_state 
                                                                            = 
                                                                            ((2U 
                                                                              == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                              ? 0U
                                                                              : 1U);
                                                                    } else {
                                                                        if (
                                                                            (1U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address;
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data;
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                                                            __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                                                                        } else {
                                                                            if (
                                                                                (2U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            if (
                                                                (0x12U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                                if (VL_UNLIKELY(
                                                                                (4U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                                                                    VL_WRITEF("RSTORE\n");
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v10 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v10 = 1U;
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                } else {
                                                                    if (vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete) {
                                                                        __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(1U) 
                                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound5 
                                                                            = 
                                                                            ((((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                ? 
                                                                               (0xffU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                                : 0U) 
                                                                              << 0x18U) 
                                                                             | (0xffffffU 
                                                                                & (((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                 : 0U) 
                                                                                >> 8U)));
                                                                        if (
                                                                            (9U 
                                                                             >= 
                                                                             (0xfU 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand1))) {
                                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v11 
                                                                                = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound5;
                                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v11 = 1U;
                                                                            __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v11 
                                                                                = 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1);
                                                                        }
                                                                        __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                                                    } else {
                                                                        if (
                                                                            (0U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index))) {
                                                                            __Vdly__test__DOT__top_instantiation__DOT__temp_address 
                                                                                = 
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                                 : 0U);
                                                                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data 
                                                                                = 
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                (0xffU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                                 : 0U);
                                                                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address 
                                                                                = 
                                                                                (0x3fffffU 
                                                                                & (((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                                 : 0U) 
                                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                            if (
                                                                                (0U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state 
                                                                                = 
                                                                                ((2U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                                 ? 0U
                                                                                 : 1U);
                                                                            } else {
                                                                                if (
                                                                                (1U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                                                                                }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data 
                                                                                = 
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                (0xffU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                                 : 0U);
                                                                            __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address 
                                                                                = 
                                                                                (0x3fffffU 
                                                                                & (vlTOPp->test__DOT__top_instantiation__DOT__temp_address 
                                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index)));
                                                                            if (
                                                                                (0U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state 
                                                                                = 
                                                                                ((2U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                                                                 ? 0U
                                                                                 : 1U);
                                                                            } else {
                                                                                if (
                                                                                (1U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                                                                = __Vtask_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state))) {
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                if (
                                                                    (3U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                                    VL_WRITEF("ADD\n");
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v12 
                                                                        = 
                                                                        (((9U 
                                                                           >= 
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                           ? 
                                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                           : 0U) 
                                                                         + 
                                                                         ((9U 
                                                                           >= 
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                           ? 
                                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                           : 0U));
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v12 = 1U;
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v13 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                } else {
                                                                    VL_WRITEF("SUB\n");
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v14 
                                                                        = 
                                                                        (((9U 
                                                                           >= 
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                           ? 
                                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                           : 0U) 
                                                                         - 
                                                                         ((9U 
                                                                           >= 
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                           ? 
                                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                           : 0U));
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v14 = 1U;
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v15 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if ((((((((
                                                   (0x14U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)) 
                                                   | (0x15U 
                                                      == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                  | (5U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                 | (6U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                | (7U 
                                                   == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                               | (8U 
                                                  == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                              | (9U 
                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                             | (0xaU 
                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                            if (VL_UNLIKELY(
                                                            (0x14U 
                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                VL_WRITEF("MULT\n");
                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v16 
                                                    = 
                                                    (((9U 
                                                       >= 
                                                       (0xfU 
                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                       ? 
                                                      vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                      [
                                                      (0xfU 
                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                       : 0U) 
                                                     * 
                                                     ((9U 
                                                       >= 
                                                       (0xfU 
                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                       ? 
                                                      vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                      [
                                                      (0xfU 
                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                       : 0U));
                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v16 = 1U;
                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v17 
                                                    = 
                                                    ((IData)(9U) 
                                                     + 
                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                     [0U]);
                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                            } else {
                                                if (
                                                    (0x15U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                    if (
                                                        (0U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter))) {
                                                        __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter)));
                                                        vlTOPp->test__DOT__top_instantiation__DOT__divider_numerator 
                                                            = 
                                                            ((9U 
                                                              >= 
                                                              (0xfU 
                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                              ? 
                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                             [
                                                             (0xfU 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                              : 0U);
                                                        vlTOPp->test__DOT__top_instantiation__DOT__divider_denominator 
                                                            = 
                                                            ((9U 
                                                              >= 
                                                              (0xfU 
                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                              ? 
                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                             [
                                                             (0xfU 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                              : 0U);
                                                    } else {
                                                        if (VL_UNLIKELY(
                                                                        (0x10U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter)))) {
                                                            VL_WRITEF("DIV\n");
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v18 
                                                                = 
                                                                ((0x10U 
                                                                  >= 
                                                                  (0x1fU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                                                  ? 
                                                                 vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe
                                                                 [
                                                                 (0x1fU 
                                                                  & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                                                  : 0U);
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v18 = 1U;
                                                            __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter = 0U;
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v19 
                                                                = 
                                                                ((0x10U 
                                                                  >= 
                                                                  (0x1fU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                                                  ? 
                                                                 vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe
                                                                 [
                                                                 (0x1fU 
                                                                  & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                                                  : 0U);
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v19 = 1U;
                                                            __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v20 
                                                                = 
                                                                ((IData)(9U) 
                                                                 + 
                                                                 vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                 [0U]);
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v20 = 1U;
                                                        } else {
                                                            __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter 
                                                                = 
                                                                (0x1fU 
                                                                 & ((IData)(1U) 
                                                                    + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter)));
                                                        }
                                                    }
                                                } else {
                                                    if (
                                                        (5U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                        if (VL_UNLIKELY(
                                                                        ((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_access_state)) 
                                                                         & (0x3ed0U 
                                                                            > 
                                                                            ((9U 
                                                                              >= 
                                                                              (0xfU 
                                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                              ? 
                                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                             [
                                                                             (0xfU 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                              : 0U))))) {
                                                            VL_WRITEF("\033[1;32mOUT [address %0#, character '%c' (integer value %0#)]\033[0m\n",
                                                                      32,
                                                                      ((9U 
                                                                        >= 
                                                                        (0xfU 
                                                                         & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                        ? 
                                                                       vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                       [
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                        : 0U),
                                                                      32,
                                                                      ((9U 
                                                                        >= 
                                                                        (0xfU 
                                                                         & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                        ? 
                                                                       vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                       [
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                        : 0U),
                                                                      32,
                                                                      ((9U 
                                                                        >= 
                                                                        (0xfU 
                                                                         & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                        ? 
                                                                       vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                       [
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                        : 0U));
                                                            vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable = 1U;
                                                            vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access 
                                                                = 
                                                                ((9U 
                                                                  >= 
                                                                  (0xfU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                  ? 
                                                                 (0x3fffU 
                                                                  & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                  [
                                                                  (0xfU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                  : 0U);
                                                            __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state = 1U;
                                                            vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_to_write 
                                                                = 
                                                                ((9U 
                                                                  >= 
                                                                  (0xfU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                  ? 
                                                                 (0xffU 
                                                                  & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                  [
                                                                  (0xfU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__operand2)])
                                                                  : 0U);
                                                        } else {
                                                            if (VL_UNLIKELY(
                                                                            (0x3ed0U 
                                                                             == 
                                                                             ((9U 
                                                                               >= 
                                                                               (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                               ? 
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [
                                                                              (0xfU 
                                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                               : 0U)))) {
                                                                VL_WRITEF("Error: CPU cannot write to interrupt value port.\n");
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v21 
                                                                    = 
                                                                    ((IData)(9U) 
                                                                     + 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [0U]);
                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v21 = 1U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            } else {
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v22 
                                                                    = 
                                                                    ((IData)(9U) 
                                                                     + 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [0U]);
                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v22 = 1U;
                                                                vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable = 0U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            }
                                                        }
                                                    } else {
                                                        if (VL_UNLIKELY(
                                                                        (6U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                            VL_WRITEF("IN\n");
                                                            if (
                                                                ((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__gpu_access_state)) 
                                                                 & (0x3ed0U 
                                                                    > 
                                                                    ((9U 
                                                                      >= 
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                      ? 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                      : 0U)))) {
                                                                vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access 
                                                                    = 
                                                                    ((9U 
                                                                      >= 
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                      ? 
                                                                     (0x3fffU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                      [
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                      : 0U);
                                                                __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state = 1U;
                                                            } else {
                                                                if (
                                                                    (0x3ed0U 
                                                                     == 
                                                                     ((9U 
                                                                       >= 
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                       ? 
                                                                      vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                      [
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                       : 0U))) {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound6 
                                                                        = vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out;
                                                                    if (
                                                                        (9U 
                                                                         >= 
                                                                         (0xfU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v23 
                                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound6;
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v23 = 1U;
                                                                        __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v23 
                                                                            = 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                                    }
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v24 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v24 = 1U;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                } else {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound7 
                                                                        = vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_read;
                                                                    if (
                                                                        (9U 
                                                                         >= 
                                                                         (0xfU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v25 
                                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound7;
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v25 = 1U;
                                                                        __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v25 
                                                                            = 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                                    }
                                                                    __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v26 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v26 = 1U;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                }
                                                            }
                                                        } else {
                                                            if (VL_UNLIKELY(
                                                                            (7U 
                                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                                VL_WRITEF("MOV\n");
                                                                vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound8 
                                                                    = 
                                                                    ((9U 
                                                                      >= 
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                      ? 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                      : 0U);
                                                                if (
                                                                    (9U 
                                                                     >= 
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand2))) {
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v27 
                                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound8;
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v27 = 1U;
                                                                    __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v27 
                                                                        = 
                                                                        (0xfU 
                                                                         & vlTOPp->test__DOT__top_instantiation__DOT__operand2);
                                                                }
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v28 
                                                                    = 
                                                                    ((IData)(9U) 
                                                                     + 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [0U]);
                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v28 = 1U;
                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            } else {
                                                                if (VL_UNLIKELY(
                                                                                (8U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                                    VL_WRITEF("CMP register %0# (value %0#), register %0# (value %0#)\n",
                                                                              32,
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__operand1,
                                                                              32,
                                                                              ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                ? 
                                                                               vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                               [
                                                                               (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                : 0U),
                                                                              32,
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__operand2,
                                                                              32,
                                                                              ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                                ? 
                                                                               vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                               [
                                                                               (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                                : 0U));
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v29 
                                                                        = 
                                                                        ((((9U 
                                                                            >= 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                            ? 
                                                                           vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                           [
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                            : 0U) 
                                                                          < 
                                                                          ((9U 
                                                                            >= 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                            ? 
                                                                           vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                           [
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                            : 0U))
                                                                          ? 0U
                                                                          : 
                                                                         ((((9U 
                                                                             >= 
                                                                             (0xfU 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                             ? 
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                            [
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                             : 0U) 
                                                                           == 
                                                                           ((9U 
                                                                             >= 
                                                                             (0xfU 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                             ? 
                                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                            [
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                             : 0U))
                                                                           ? 1U
                                                                           : 2U));
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v29 = 1U;
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v30 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                } else {
                                                                    if (
                                                                        (9U 
                                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                                        VL_WRITEF("JMPL\n");
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v31 
                                                                            = 
                                                                            ((0U 
                                                                              == 
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [1U])
                                                                              ? 
                                                                             (vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
                                                                              + vlTOPp->test__DOT__top_instantiation__DOT__operand1)
                                                                              : 
                                                                             ((IData)(9U) 
                                                                              + 
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [0U]));
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v31 = 1U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                    } else {
                                                                        VL_WRITEF("JMPE\n");
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v32 
                                                                            = 
                                                                            ((1U 
                                                                              == 
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [1U])
                                                                              ? 
                                                                             (vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
                                                                              + vlTOPp->test__DOT__top_instantiation__DOT__operand1)
                                                                              : 
                                                                             ((IData)(9U) 
                                                                              + 
                                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [0U]));
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v32 = 1U;
                                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if ((((
                                                   (((((0xbU 
                                                        == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)) 
                                                       | (0x16U 
                                                          == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                      | (0x17U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                     | (0x18U 
                                                        == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                    | (0x19U 
                                                       == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                   | (0xeU 
                                                      == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                  | (0xfU 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) 
                                                 | (0xcU 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                if (VL_UNLIKELY(
                                                                (0xbU 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                    VL_WRITEF("JMPG\n");
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v33 
                                                        = 
                                                        ((2U 
                                                          == 
                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                          [1U])
                                                          ? 
                                                         (vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
                                                          + vlTOPp->test__DOT__top_instantiation__DOT__operand1)
                                                          : 
                                                         ((IData)(9U) 
                                                          + 
                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                          [0U]));
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v33 = 1U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                } else {
                                                    if (
                                                        (0x16U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v34 
                                                            = 
                                                            (((9U 
                                                               >= 
                                                               (0xfU 
                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                               ? 
                                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                              [
                                                              (0xfU 
                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                               : 0U) 
                                                             | ((9U 
                                                                 >= 
                                                                 (0xfU 
                                                                  & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                 ? 
                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                [
                                                                (0xfU 
                                                                 & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                 : 0U));
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v34 = 1U;
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v35 
                                                            = 
                                                            ((IData)(9U) 
                                                             + 
                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                             [0U]);
                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                    } else {
                                                        if (
                                                            (0x17U 
                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v36 
                                                                = 
                                                                (((9U 
                                                                   >= 
                                                                   (0xfU 
                                                                    & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                   ? 
                                                                  vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                  [
                                                                  (0xfU 
                                                                   & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                   : 0U) 
                                                                 & ((9U 
                                                                     >= 
                                                                     (0xfU 
                                                                      & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                     ? 
                                                                    vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                    [
                                                                    (0xfU 
                                                                     & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                     : 0U));
                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v36 = 1U;
                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v37 
                                                                = 
                                                                ((IData)(9U) 
                                                                 + 
                                                                 vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                 [0U]);
                                                            __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                        } else {
                                                            if (
                                                                (0x18U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v38 
                                                                    = 
                                                                    (((9U 
                                                                       >= 
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                       ? 
                                                                      vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                      [
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                       : 0U) 
                                                                     ^ 
                                                                     ((9U 
                                                                       >= 
                                                                       (0xfU 
                                                                        & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                       ? 
                                                                      vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                      [
                                                                      (0xfU 
                                                                       & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                       : 0U));
                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v38 = 1U;
                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v39 
                                                                    = 
                                                                    ((IData)(9U) 
                                                                     + 
                                                                     vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                     [0U]);
                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                            } else {
                                                                if (
                                                                    (0x19U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound9 
                                                                        = 
                                                                        (~ 
                                                                         ((9U 
                                                                           >= 
                                                                           (0xfU 
                                                                            & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                           ? 
                                                                          vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                          [
                                                                          (0xfU 
                                                                           & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                           : 0U));
                                                                    if (
                                                                        (9U 
                                                                         >= 
                                                                         (0xfU 
                                                                          & vlTOPp->test__DOT__top_instantiation__DOT__operand1))) {
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v40 
                                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound9;
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v40 = 1U;
                                                                        __Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v40 
                                                                            = 
                                                                            (0xfU 
                                                                             & vlTOPp->test__DOT__top_instantiation__DOT__operand1);
                                                                    }
                                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v41 
                                                                        = 
                                                                        ((IData)(9U) 
                                                                         + 
                                                                         vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                         [0U]);
                                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v41 = 1U;
                                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                } else {
                                                                    if (VL_UNLIKELY(
                                                                                (0xeU 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                                        VL_WRITEF("ISR\nSetting interrupt No. %10# to address %10#.\n",
                                                                                32,
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                 : 0U),
                                                                                32,
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                                 : 0U));
                                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 
                                                                            = 
                                                                            ((9U 
                                                                              >= 
                                                                              (0xfU 
                                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand2))
                                                                              ? 
                                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                             [
                                                                             (0xfU 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__operand2)]
                                                                              : 0U);
                                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 = 1U;
                                                                        __Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 
                                                                            = 
                                                                            ((9U 
                                                                              >= 
                                                                              (0xfU 
                                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                              ? 
                                                                             (7U 
                                                                              & vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                              [
                                                                              (0xfU 
                                                                               & vlTOPp->test__DOT__top_instantiation__DOT__operand1)])
                                                                              : 0U);
                                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v42 
                                                                            = 
                                                                            ((IData)(9U) 
                                                                             + 
                                                                             vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                             [0U]);
                                                                    } else {
                                                                        if (VL_LIKELY(
                                                                                (0xfU 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                                            if (
                                                                                (0U 
                                                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))) {
                                                                                VL_WRITEF("Triggering interrupt No. %10#.\n",
                                                                                32,
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                 : 0U));
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_in 
                                                                                = 
                                                                                ((9U 
                                                                                >= 
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1))
                                                                                 ? 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [
                                                                                (0xfU 
                                                                                & vlTOPp->test__DOT__top_instantiation__DOT__operand1)]
                                                                                 : 0U);
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write = 1U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 2U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in = 0U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 1U;
                                                                            } else {
                                                                                VL_WRITEF("INT\n");
                                                                                __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v43 
                                                                                = 
                                                                                ((IData)(9U) 
                                                                                + 
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                                                [0U]);
                                                                                __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v43 = 1U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
                                                                                vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
                                                                                __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                            }
                                                                        } else {
                                                                            VL_WRITEF("RST\n");
                                                                            __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v44 
                                                                                = vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address;
                                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v44 = 1U;
                                                                            __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                                            __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v46 = 1U;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (VL_UNLIKELY(
                                                                (0x10U 
                                                                 == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation)))) {
                                                    VL_WRITEF("ENDINT\n");
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [0U];
                                                    vlTOPp->test__DOT__top_instantiation__DOT__i = 0xaU;
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v52 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v52 = 1U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__state = 6U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [1U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v53 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v53 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [2U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v54 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v54 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [3U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v55 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v55 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [4U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v56 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v56 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [5U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v57 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v57 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [6U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v58 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v58 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [7U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v59 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v59 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [8U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v60 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v60 = 1U;
                                                    vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10 
                                                        = 
                                                        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers
                                                        [9U];
                                                    __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v61 
                                                        = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound10;
                                                    __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v61 = 1U;
                                                } else {
                                                    if (
                                                        (0xdU 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__operation))) {
                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 5U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if ((6U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__state))) {
                                        if (((0U != 
                                              vlTOPp->test__DOT__top_instantiation__DOT__registers
                                              [9U]) 
                                             | (((0U 
                                                  == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                                  ? 1U
                                                  : 0U) 
                                                & (0U 
                                                   == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))))) {
                                            __Vdly__test__DOT__top_instantiation__DOT__state = 7U;
                                        } else {
                                            if ((((0U 
                                                   != 
                                                   (~ 
                                                    vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                    [9U])) 
                                                  & (~ 
                                                     ((0U 
                                                       == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                                       ? 1U
                                                       : 0U))) 
                                                 & (0U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state)))) {
                                                __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read = 1U;
                                                __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 1U;
                                                __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 1U;
                                            } else {
                                                if (
                                                    (1U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))) {
                                                    __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read = 0U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 0U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 2U;
                                                } else {
                                                    if (VL_UNLIKELY(
                                                                    (2U 
                                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state)))) {
                                                        VL_WRITEF("interrupt_fifo_data_out: %10#\n",
                                                                  32,
                                                                  vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_out);
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v62 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [0U];
                                                        vlTOPp->test__DOT__top_instantiation__DOT__i = 0xaU;
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v0 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v0 = 1U;
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v63 
                                                            = 
                                                            (vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
                                                             + 
                                                             vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table
                                                             [
                                                             (7U 
                                                              & vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_out)]);
                                                        __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
                                                        __Vdly__test__DOT__top_instantiation__DOT__state = 7U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [1U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v1 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v1 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [2U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v2 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v2 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [3U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v3 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v3 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [4U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v4 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v4 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [5U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v5 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v5 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [6U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v6 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v6 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [7U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v7 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v7 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [8U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v8 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v8 = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11 
                                                            = 
                                                            vlTOPp->test__DOT__top_instantiation__DOT__registers
                                                            [9U];
                                                        __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v9 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT____Vlvbound11;
                                                        __Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v9 = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if ((((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                               ? 1U
                                               : 0U) 
                                             & (0U 
                                                == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state)))) {
                                            __Vdly__test__DOT__top_instantiation__DOT__state = 2U;
                                        } else {
                                            if (((~ 
                                                  ((0U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                                    ? 1U
                                                    : 0U)) 
                                                 & (0U 
                                                    == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state)))) {
                                                __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 1U;
                                                __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 1U;
                                            } else {
                                                if (
                                                    (1U 
                                                     == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                                                    __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 0U;
                                                    __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 2U;
                                                } else {
                                                    if (
                                                        (2U 
                                                         == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                                                        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write = 1U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_in = 0U;
                                                        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in 
                                                            = vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out;
                                                        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 1U;
                                                        __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 3U;
                                                    } else {
                                                        if (
                                                            (3U 
                                                             == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                                                            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
                                                            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
                                                            __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 0U;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        __Vdly__test__DOT__top_instantiation__DOT__operand1 = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__operand2 = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v64 = 1U;
        vlTOPp->test__DOT__top_instantiation__DOT__i = 8U;
        __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i = 1U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
        __Vdly__test__DOT__top_instantiation__DOT__program_rom_address = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__program_rom_read_state = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__state = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__operation = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_stabilization_counter = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_write_state = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_read_state = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__ram_read_data = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v65 = 1U;
        __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_to_write = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_in = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__program_end_address = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__divider_numerator = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__divider_denominator = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__temp_address = 0U;
        __Vdlyvset__test__DOT__top_instantiation__DOT__registers__v66 = 1U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_read 
        = __Vdly__test__DOT__top_instantiation__DOT__gpu_character_read;
    vlTOPp->test__DOT__top_instantiation__DOT__state 
        = __Vdly__test__DOT__top_instantiation__DOT__state;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address 
        = __Vdly__test__DOT__top_instantiation__DOT__code_section_start_address;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_write_complete;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_write_state;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_read_state;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_read_data;
    vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete 
        = __Vdly__test__DOT__top_instantiation__DOT__ram_read_complete;
    vlTOPp->test__DOT__top_instantiation__DOT__operation 
        = __Vdly__test__DOT__top_instantiation__DOT__operation;
    vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index 
        = __Vdly__test__DOT__top_instantiation__DOT__operand_byte_index;
    vlTOPp->test__DOT__top_instantiation__DOT__operand1 
        = __Vdly__test__DOT__top_instantiation__DOT__operand1;
    vlTOPp->test__DOT__top_instantiation__DOT__operand2 
        = __Vdly__test__DOT__top_instantiation__DOT__operand2;
    vlTOPp->test__DOT__top_instantiation__DOT__temp_address 
        = __Vdly__test__DOT__top_instantiation__DOT__temp_address;
    vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter 
        = __Vdly__test__DOT__top_instantiation__DOT__division_delay_counter;
    vlTOPp->test__DOT__top_instantiation__DOT__gpu_access_state 
        = __Vdly__test__DOT__top_instantiation__DOT__gpu_access_state;
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state 
        = __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state 
        = __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = __Vdly__test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[__Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[__Vdlyvdim0__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[__Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v65) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[0U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v66) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[1U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[4U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[5U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[6U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[7U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v1) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v1;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v2) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[2U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v2;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v3) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[3U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v3;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v4) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[4U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v4;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v5) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[5U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v5;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v6) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[6U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v6;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v7) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[7U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v7;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v8) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[8U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v8;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v9) {
        vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[9U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__shadow_registers__v9;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v1) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v1;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v2) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v2;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v3) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v3] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v3;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v4) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v4] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v4;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v5) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v5;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v6) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v6] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v6;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v7) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v7;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v8) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v8;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v9) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v9] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v9;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v10) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v10;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v11) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v11] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v11;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v12) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v12;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v13;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v14) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v14;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v15;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v16) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v16;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v17;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v18) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v18;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v19) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[2U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v19;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v20) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v20;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v21) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v21;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v22) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v22;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v23) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v23] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v23;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v24) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v24;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v25) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v25] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v25;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v26) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v26;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v27) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v27] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v27;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v28) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v28;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v29) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v29;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v30;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v31) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v31;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v32) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v32;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v33) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v33;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v34) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v34;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v35;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v36) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v36;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v37;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v38) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v38;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v39;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v40) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__test__DOT__top_instantiation__DOT__registers__v40] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v40;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v41) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v41;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_vector_table__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v42;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v43) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v43;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v44) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v44;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v46) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[4U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[5U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[6U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[7U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v52) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v52;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v53) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v53;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v54) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[2U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v54;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v55) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[3U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v55;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v56) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[4U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v56;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v57) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[5U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v57;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v58) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[6U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v58;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v59) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[7U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v59;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v60) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[8U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v60;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v61) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[9U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v61;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v62) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[9U] = 1U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__shadow_registers__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__registers__v63;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v64) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[0U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v65) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[1U] = 0U;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__registers__v66) {
        vlTOPp->test__DOT__top_instantiation__DOT__registers[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[4U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[5U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[6U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[7U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[8U] = 1U;
        vlTOPp->test__DOT__top_instantiation__DOT__registers[9U] = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__program_rom_byte 
        = ((0x107aU >= (0x1fffU & vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address))
            ? vlTOPp->test__DOT__top_instantiation__DOT__program_rom__DOT__rom_memory
           [(0x1fffU & vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address)]
            : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_numer 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider_numerator;
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_denom 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider_denominator;
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_q 
        = VL_DIV_III(32, vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_numer, vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_r 
        = VL_MODDIV_III(32, vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_numer, vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_q;
    vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain 
        = vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_r;
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_read) 
             & (~ ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out 
                = ((9U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))
                    ? vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items
                   [vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer]
                    : 0U);
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer 
                = ((9U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out = 0U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_read) 
             & (~ ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_out 
                = ((9U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))
                    ? vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items
                   [vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer]
                    : 0U);
            vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer 
                = ((9U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_out = 0U;
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read) 
             & (~ ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out 
                = ((4U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))
                    ? vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items
                   [vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer]
                    : 0U);
            vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer 
                = ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))));
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address 
        = __Vdly__test__DOT__top_instantiation__DOT__program_rom_address;
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_read 
        = __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[__Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[0U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[1U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[4U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[5U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[6U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[7U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[8U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[9U] = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
        = __Vdly__test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_read 
        = __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[__Vdlyvdim0__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1) {
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[0U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[1U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[4U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[5U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[6U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[7U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[8U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[9U] = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
        = __Vdly__test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read 
        = __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[__Vdlyvdim0__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0] 
            = __Vdlyvval__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1) {
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[0U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[1U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[2U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[3U] = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[4U] = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
        = __Vdly__test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    vlTOPp->test__DOT__top_instantiation__DOT__program_rom_done 
        = (0x107aU == vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address);
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full 
        = ((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty 
        = ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_full 
        = ((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_empty 
        = ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__GPIO_0 
        = ((0xfffffff00ULL & vlTOPp->test__DOT__top_instantiation__DOT__GPIO_0) 
           | (IData)((IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out)));
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full 
        = ((5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty 
        = ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
}

VL_INLINE_OPT void Vtest::_sequent__TOP__3(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__3\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp35[4];
    // Body
    if (vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking) {
        vlTOPp->test__DOT__VGA_B = 0U;
        vlTOPp->test__DOT__VGA_G = 0U;
        vlTOPp->test__DOT__VGA_R = 0U;
    } else {
        vlTOPp->test__DOT__VGA_B = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value)
                                     ? 0xfU : 0U);
        vlTOPp->test__DOT__VGA_G = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value)
                                     ? 0xfU : 0U);
        vlTOPp->test__DOT__VGA_R = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value)
                                     ? 0xfU : 0U);
    }
    __Vtemp35[0U] = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][0U];
    __Vtemp35[1U] = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][1U];
    __Vtemp35[2U] = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][2U];
    __Vtemp35[3U] = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][3U];
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value 
        = ((0x7fU >= (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                       << 3U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) 
           & (__Vtemp35[(3U & (((IData)(0x7fU) - (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                                                   << 3U) 
                                                  + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) 
                               >> 5U))] >> (0x1fU & 
                                            ((IData)(0x7fU) 
                                             - (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                                                 << 3U) 
                                                + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))))));
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character 
        = ((0x3ecfU >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell))
            ? vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer
           [vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell]
            : 0U);
}

VL_INLINE_OPT void Vtest::_sequent__TOP__4(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__4\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*8:0*/ __Vtableidx1;
    // Body
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller_init_done 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o 
        = ((IData)(vlTOPp->reset) & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid) 
                                     >> 2U));
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
            = ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter))
                ? 0x30dU : (0x1fffU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter) 
                                       - (IData)(1U))));
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller_init_done 
            = (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done) 
                | (5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) 
               & 1U);
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh 
            = (((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter)) 
                & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)) 
               & 1U);
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o 
            = vlTOPp->test__DOT__DRAM_DQ;
    } else {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter = 0x1388U;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller_init_done = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o = 0U;
    }
    __Vtableidx1 = (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) 
                     << 8U) | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty) 
                                << 7U) | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) 
                                           << 6U) | 
                                          (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries) 
                                            << 4U) 
                                           | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o) 
                                               << 3U) 
                                              | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->reset))))))));
    if ((1U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
            = vlTOPp->__Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries
            [__Vtableidx1];
    }
    if ((2U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
            = vlTOPp->__Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address
            [__Vtableidx1];
    }
    if ((4U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address 
            = vlTOPp->__Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address
            [__Vtableidx1];
    }
    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
        = ((IData)(vlTOPp->reset) & ((((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter)) 
                                       | (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)) 
                                      & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request))) 
                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done)));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid 
        = ((IData)(vlTOPp->reset) ? (7U & (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid) 
                                            << 1U) 
                                           | (5U == 
                                              (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))))
            : 0U);
}

VL_INLINE_OPT void Vtest::_sequent__TOP__5(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__5\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    CData/*7:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    CData/*3:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    SData/*13:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    SData/*11:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    SData/*12:0*/ __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    // Body
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
        = vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    if (VL_LIKELY(vlTOPp->reset)) {
        if ((1U & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking)))) {
            if ((0xf0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column))) {
                if ((0xfU != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y))) {
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
                        = (0x3fffU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell) 
                                      - (IData)(0xf0U)));
                }
                __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
                __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column = 0U;
            } else {
                if ((7U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) {
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column)));
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
                        = (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell)));
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
                } else {
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x)));
                }
            }
            if (((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x)) 
                 & (0U == ((0x438U <= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))
                            ? 0x437U : (0x7ffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))) {
                __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell = 0U;
                __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y = 0U;
            } else {
                if ((0x780U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x))) {
                    __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
                        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y)));
                }
            }
        }
    } else {
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell = 0U;
        VL_WRITEF("In reset.\n");
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column = 0U;
    }
    if (VL_LIKELY(vlTOPp->reset)) {
        if ((0x898U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count))) {
            __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
                = (0xfffU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)));
            __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count = 0U;
        } else {
            __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
                = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)));
        }
        if ((0x465U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))) {
            __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count = 0U;
        }
    } else {
        VL_WRITEF("Resetting...\n");
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count = 0U;
        __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
        = __Vdly__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x 
        = ((0x118U > (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count))
            ? 0U : (0xfffU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count) 
                              - (IData)(0x118U))));
    vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking 
        = ((0x118U > (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
           | (0x437U < (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)));
}

VL_INLINE_OPT void Vtest::_sequent__TOP__6(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__6\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__test__DOT__sdram_module__DOT__mem_array__v0;
    CData/*2:0*/ __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe;
    SData/*15:0*/ __Vdlyvval__test__DOT__sdram_module__DOT__mem_array__v0;
    IData/*21:0*/ __Vdlyvdim0__test__DOT__sdram_module__DOT__mem_array__v0;
    // Body
    __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe 
        = vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe;
    __Vdlyvset__test__DOT__sdram_module__DOT__mem_array__v0 = 0U;
    __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe 
        = ((3U & (IData)(__Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe)) 
           | (4U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe) 
                    << 1U)));
    __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe 
        = ((5U & (IData)(__Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe)) 
           | (2U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe) 
                    << 1U)));
    __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe 
        = ((6U & (IData)(__Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe)) 
           | (0x205244U == vlTOPp->test__DOT__sdram_module__DOT__CODE));
    if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr) 
         & (2U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)))) {
        if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) {
            if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) {
                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1 
                    = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
            }
        }
    }
    if (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr) 
         & (2U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)))) {
        if ((1U & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address)))) {
            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0 
                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
        }
    }
    if ((0x205752U == vlTOPp->test__DOT__sdram_module__DOT__CODE)) {
        __Vdlyvval__test__DOT__sdram_module__DOT__mem_array__v0 
            = vlTOPp->test__DOT__sdram_module__DOT__rmw_temp;
        __Vdlyvset__test__DOT__sdram_module__DOT__mem_array__v0 = 1U;
        __Vdlyvdim0__test__DOT__sdram_module__DOT__mem_array__v0 
            = vlTOPp->test__DOT__sdram_module__DOT__test_addr;
    }
    vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_2 
        = vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1;
    vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_2 
        = vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_1;
    if ((0x4c4d52U == vlTOPp->test__DOT__sdram_module__DOT__CODE)) {
        vlTOPp->test__DOT__sdram_module__DOT__latency 
            = (7U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr) 
                     >> 4U));
    }
    if ((0x414354U == vlTOPp->test__DOT__sdram_module__DOT__CODE)) {
        vlTOPp->test__DOT__sdram_module__DOT__addr_crb 
            = ((0x2000U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                           << 0xcU)) | (((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr) 
                                         << 1U) | (1U 
                                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
    }
    vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe 
        = __Vdly__test__DOT__sdram_module__DOT__rd_valid_pipe;
    if (__Vdlyvset__test__DOT__sdram_module__DOT__mem_array__v0) {
        vlTOPp->test__DOT__sdram_module__DOT__mem_array[__Vdlyvdim0__test__DOT__sdram_module__DOT__mem_array__v0] 
            = __Vdlyvval__test__DOT__sdram_module__DOT__mem_array__v0;
    }
    vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1 
        = vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0;
    vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_1 
        = vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_0;
    vlTOPp->test__DOT__sdram_module__DOT__read_valid 
        = (1U & ((0U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                               - (IData)(1U)))) ? (IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe)
                  : ((1U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                   - (IData)(1U))))
                      ? ((IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe) 
                         >> 1U) : ((IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe) 
                                   >> 2U))));
    vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0 
        = vlTOPp->test__DOT__sdram_module__DOT__test_addr;
    vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_0 
        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
    vlTOPp->test__DOT__sdram_module__DOT__read_mask 
        = ((0U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                         - (IData)(1U)))) ? (IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_0)
            : ((1U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                             - (IData)(1U)))) ? (IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_1)
                : (IData)(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_2)));
    vlTOPp->test__DOT__sdram_module__DOT__zs_dq__out__en0 
        = ((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_valid)
            ? (0xffffU & (((1U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                            ? 0U : 0xffU) | (((2U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                                               ? 0U
                                               : 0xffU) 
                                             << 8U)))
            : 0U);
}

VL_INLINE_OPT void Vtest::_sequent__TOP__7(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__7\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished) {
        vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__other_done = 1U;
    } else {
        if (vlTOPp->clk) {
            vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__other_done = 0U;
        }
    }
}

VL_INLINE_OPT void Vtest::_sequent__TOP__8(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__8\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    // Body
    __Vdly__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
        = vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
        = (0x7ffU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register) 
                     >> 1U));
    vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
        = (0x200U | (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register));
    __Vdly__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
        = (0xfU & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter)));
    if ((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter))) {
        __Vdly__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__done = 1U;
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__done = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
        = __Vdly__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished 
        = (0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter));
}

VL_INLINE_OPT void Vtest::_sequent__TOP__10(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__10\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0) {
        vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer[vlTOPp->__Vdlyvdim0__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0] 
            = vlTOPp->__Vdlyvval__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data 
        = (((QData)((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            << 0x28U) | (((QData)((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i)) 
                          << 0x12U) | (QData)((IData)(
                                                      ((((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)
                                                          ? 0U
                                                          : (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i)) 
                                                        << 0x10U) 
                                                       | (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i))))));
}

VL_INLINE_OPT void Vtest::_sequent__TOP__11(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_sequent__TOP__11\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
        if (((((((((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state)) 
                   | (2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                  | (4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                 | (8U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                | (0x10U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
               | (0x20U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
              | (0x40U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
             | (0x80U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state)))) {
            if ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done) {
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)
                            ? 7U : 0xfU);
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 0U;
                    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x40U;
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 0x80U;
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 1U;
                    } else {
                        if ((0U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))) {
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                                = (1U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x28U)));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                = (0x3fffffU & (IData)(
                                                       (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                        >> 0x12U)));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                                = (0xffffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                                = (3U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x10U)));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 2U;
                        }
                    }
                } else {
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 1U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd;
                }
            } else {
                if ((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                        = (3U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                 << 3U));
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                        = (0xfffU & (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                     >> 9U));
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
                        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw)
                            ? 8U : 0x10U);
                } else {
                    if ((4U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                            = ((0x80U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next))
                                ? 7U : (7U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                              << 3U)));
                        if ((1U < (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count))) {
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
                                = (7U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count) 
                                         - (IData)(1U)));
                        } else {
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
                                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
                        }
                    } else {
                        if ((8U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                = (5U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                         << 3U));
                            if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) {
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                                    = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                                    = (3U & (IData)(
                                                    (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                     >> 0x10U)));
                            } else {
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                                    = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                                    = (3U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm));
                            }
                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
                            if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending) {
                                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 2U;
                                } else {
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                                        = (1U & (IData)(
                                                        (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                         >> 0x28U)));
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                        = (0x3fffffU 
                                           & (IData)(
                                                     (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                      >> 0x12U)));
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                                        = (0xffffU 
                                           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                                        = (3U & (IData)(
                                                        (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                         >> 0x10U)));
                                }
                            } else {
                                if (((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending)) 
                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop))) {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                        = (7U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                                 << 3U));
                                }
                                vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x100U;
                            }
                        } else {
                            if ((0x10U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                    = (4U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                             << 3U));
                                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                                        = (0xffffU 
                                           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                                        = (3U & (IData)(
                                                        (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                         >> 0x10U)));
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
                                } else {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                                        = (0xffffU 
                                           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data));
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                                        = (3U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm));
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                                        = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                                }
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                                    = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
                                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 1U;
                                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending) {
                                    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                                    } else {
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                                            = (1U & (IData)(
                                                            (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                             >> 0x28U)));
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                            = (0x3fffffU 
                                               & (IData)(
                                                         (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                          >> 0x12U)));
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                                            = (0xffffU 
                                               & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                                            = (3U & (IData)(
                                                            (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                             >> 0x10U)));
                                    }
                                } else {
                                    if (((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending)) 
                                         & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop))) {
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                            = (7U | 
                                               ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                                << 3U));
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
                                    }
                                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x100U;
                                }
                            } else {
                                if ((0x20U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                        = (7U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                                 << 3U));
                                    if ((1U < (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count))) {
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
                                            = (7U & 
                                               ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count) 
                                                - (IData)(1U)));
                                    } else {
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x40U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
                                    }
                                } else {
                                    if ((0x40U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr = 0xfffU;
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                                            = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)
                                                ? 2U
                                                : (2U 
                                                   | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                                      << 3U)));
                                    } else {
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 1U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                                        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 1U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 3U;
                                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x100U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = (7U | ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                             << 3U));
                if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                } else {
                    if ((0U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))) {
                        if (((((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match) 
                               & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match)) 
                              & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match)) 
                             & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match))) {
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
                                = ((1U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                  >> 0x28U)))
                                    ? 8U : 0x10U);
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                                = (1U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x28U)));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                = (0x3fffffU & (IData)(
                                                       (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                        >> 0x12U)));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                                = (0xffffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                                = (3U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x10U)));
                        } else {
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x20U;
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                            vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                        }
                    }
                }
            } else {
                vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
                    = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 0xfU;
                vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
                vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
            }
        }
    } else {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 1U;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 0xfU;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm = 0U;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller_init_done;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
    if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
        if (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
            vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1;
        }
    } else {
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
            = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0;
    }
    if (vlTOPp->reset) {
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0xfffU;
        if ((4U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
            if ((2U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                if ((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0U;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0x30U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 4U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 5U;
                } else {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 0U;
                }
            } else {
                vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
                    = ((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))
                        ? 5U : 0U);
            }
        } else {
            if ((2U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                if ((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 7U;
                    if ((1U < (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count))) {
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
                            = (7U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count) 
                                     - (IData)(1U)));
                    } else {
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
                            = vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
                    }
                } else {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs)));
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 1U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 3U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
                        = ((1U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs))
                            ? 7U : 2U);
                }
            } else {
                if ((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 2U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 0U;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 2U;
                } else {
                    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0xfU;
                    vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs = 0U;
                    if ((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter))) {
                        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 1U;
                    }
                }
            }
        }
    } else {
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 0U;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 0U;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0xfU;
        vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0xfffU;
        vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 0U;
    }
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match 
        = (1U & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o 
        = (2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty 
        = (0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank 
        = ((2U & (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                  >> 0x14U)) | (1U & (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                      >> 8U)));
    vlTOPp->test__DOT__sdram_module__DOT__CODE = ((8U 
                                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))
                                                   ? 0x494e48U
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x4c4d52U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x415246U
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x505245U
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                       ? 0x414354U
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                        ? 0x205752U
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                         ? 0x205244U
                                                         : 
                                                        ((6U 
                                                          == 
                                                          (7U 
                                                           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                          ? 0x425354U
                                                          : 
                                                         ((7U 
                                                           == 
                                                           (7U 
                                                            & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                           ? 0x4e4f50U
                                                           : 0x424144U)))))))));
    vlTOPp->test__DOT__sdram_module__DOT__test_addr 
        = (((IData)(vlTOPp->test__DOT__sdram_module__DOT__addr_crb) 
            << 8U) | (0xffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr)));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match 
        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw) 
           == (1U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                             >> 0x28U))));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match 
        = ((0xfffU & (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                      >> 9U)) == (0xfffU & (IData)(
                                                   (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x1bU))));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank 
        = ((2U & ((IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                           >> 0x27U)) << 1U)) | (1U 
                                                 & (IData)(
                                                           (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                            >> 0x1aU))));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
        = vlTOPp->__Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
    vlTOPp->test__DOT__sdram_module__DOT__read_data 
        = vlTOPp->test__DOT__sdram_module__DOT__mem_array
        [((0x205752U == vlTOPp->test__DOT__sdram_module__DOT__CODE)
           ? vlTOPp->test__DOT__sdram_module__DOT__test_addr
           : ((0U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                            - (IData)(1U)))) ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0
               : ((1U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                - (IData)(1U)))) ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1
                   : vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_2)))];
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match 
        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank) 
           == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank));
    vlTOPp->test__DOT__sdram_module__DOT__read_temp__out1 
        = ((0xff00U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out1)) 
           | ((1U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
               ? 0U : (0xffU & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_data))));
    vlTOPp->test__DOT__sdram_module__DOT__read_temp__out2 
        = ((0xffU & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out2)) 
           | (((2U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                ? 0U : (0xffU & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_data) 
                                 >> 8U))) << 8U));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending 
        = (((((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)) 
              & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match)) 
             & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match)) 
            & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match)) 
           & (0U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
    vlTOPp->test__DOT__DRAM_DQ = (((((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_valid)
                                      ? (((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out1) 
                                          & ((1U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                                              ? 0U : 0xffU)) 
                                         | ((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out2) 
                                            & (((2U 
                                                 & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                                                 ? 0U
                                                 : 0xffU) 
                                               << 8U)))
                                      : 0U) & (IData)(vlTOPp->test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                   & (IData)(vlTOPp->test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                  | (((((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                         ? (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data)
                                         : 0U) & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                   ? 0xffffU
                                                   : 0U)) 
                                      & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                          ? 0xffffU
                                          : 0U)) & 
                                     ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                       ? 0xffffU : 0U)));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select 
        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop) 
           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
    vlTOPp->test__DOT__sdram_module__DOT__rmw_temp 
        = ((0xff00U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__rmw_temp)) 
           | (0xffU & ((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))
                        ? (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_data)
                        : (IData)(vlTOPp->test__DOT__DRAM_DQ))));
    vlTOPp->test__DOT__sdram_module__DOT__rmw_temp 
        = ((0xffU & (IData)(vlTOPp->test__DOT__sdram_module__DOT__rmw_temp)) 
           | (0xff00U & (((2U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))
                           ? ((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_data) 
                              >> 8U) : ((IData)(vlTOPp->test__DOT__DRAM_DQ) 
                                        >> 8U)) << 8U)));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n 
        = ((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr 
        = (0xffU & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)
                     ? (0xffU & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x12U)))
                     : (0xffU & vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr)));
}

VL_INLINE_OPT void Vtest::_multiclk__TOP__12(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_multiclk__TOP__12\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_ready 
        = ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__done) 
           & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__other_done));
}

VL_INLINE_OPT void Vtest::_multiclk__TOP__13(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_multiclk__TOP__13\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr 
        = (((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            | (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i))) 
           & (2U != (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
}

void Vtest::_eval(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_eval\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->vga_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__vga_clk_supplied)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->dram_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__dram_clk_supplied))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)) 
         | ((IData)(vlTOPp->vga_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__vga_clk_supplied))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    if (((IData)(vlTOPp->dram_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__dram_clk_supplied)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->test__DOT__PS2_CLK) & 
             (~ (IData)(vlTOPp->__Vclklast__TOP__test__DOT__PS2_CLK)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->test__DOT__PS2_CLK)) & (IData)(vlTOPp->__Vclklast__TOP__test__DOT__PS2_CLK))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity[6U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if ((((IData)(vlTOPp->dram_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__dram_clk_supplied))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
        vlTOPp->__Vm_traceActivity[7U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->test__DOT__PS2_CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__test__DOT__PS2_CLK))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished))))) {
        vlTOPp->_multiclk__TOP__12(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->dram_clk_supplied) & (~ (IData)(vlTOPp->__Vclklast__TOP__dram_clk_supplied)))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_multiclk__TOP__13(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__vga_clk_supplied = vlTOPp->vga_clk_supplied;
    vlTOPp->__Vclklast__TOP__dram_clk_supplied = vlTOPp->dram_clk_supplied;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP__test__DOT__PS2_CLK = vlTOPp->test__DOT__PS2_CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished 
        = vlTOPp->__VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
    vlTOPp->__VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished 
        = vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
}

VL_INLINE_OPT QData Vtest::_change_request(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_change_request\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtest::_change_request_1(Vtest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_change_request_1\n"); );
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished ^ vlTOPp->__Vchglast__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished));
    VL_DEBUG_IF( if(__req && ((vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished ^ vlTOPp->__Vchglast__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished))) VL_DBG_MSGF("        CHANGE: keyboard.v:40: test.top_instantiation.ps2_keyboard.bits_counter_finished\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished 
        = vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
    return __req;
}

#ifdef VL_DEBUG
void Vtest::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((dram_clk_supplied & 0xfeU))) {
        Verilated::overWidthError("dram_clk_supplied");}
    if (VL_UNLIKELY((vga_clk_supplied & 0xfeU))) {
        Verilated::overWidthError("vga_clk_supplied");}
}
#endif  // VL_DEBUG
