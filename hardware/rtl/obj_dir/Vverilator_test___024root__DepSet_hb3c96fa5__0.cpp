// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_test.h for the primary calling header

#include "verilated.h"

#include "Vverilator_test___024root.h"

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__2(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hf5b3c59a__0;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hc49af5e7__0;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address;
    SData/*15:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address;
    SData/*15:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address;
    SData/*15:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address;
    SData/*15:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data;
    IData/*21:0*/ __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__35__ram_read_address;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__state;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v0;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__program_rom_address;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state;
    SData/*15:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__operation;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__operand1;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__operand2;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v1;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v1;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v2;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v2;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v3;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v3;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v3;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v4;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v4;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v4;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v5;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v5;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v6;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v6;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v6;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v7;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v7;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v8;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v8;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v9;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v9;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v9;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v10;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v10;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v11;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v11;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v11;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v12;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v12;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v13;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v14;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v14;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v15;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v16;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v16;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v17;
    CData/*4:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v18;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v18;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v19;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v19;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v20;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v20;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v21;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v21;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v22;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v22;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v23;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v23;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v24;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v24;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v25;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v25;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v25;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v26;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v26;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v27;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v27;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v27;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v28;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v28;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v29;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v29;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v29;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v30;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v30;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v31;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v31;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v31;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v32;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v32;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v33;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v33;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v34;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v35;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v35;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v36;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v36;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v37;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v37;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v38;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v38;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v39;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v40;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v40;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v41;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v42;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v42;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v43;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v44;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v44;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v44;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v45;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v45;
    CData/*2:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v46;
    CData/*1:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v47;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v47;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v48;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v48;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v49;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v58;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v58;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v59;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v59;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v60;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v60;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v61;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v61;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v62;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v62;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v63;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v63;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v64;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v64;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v65;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v65;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v66;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v66;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v67;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v67;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v68;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v69;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v70;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v71;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v72;
    CData/*3:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1;
    CData/*3:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    CData/*3:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer;
    CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
    SData/*10:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register;
    CData/*3:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    CData/*2:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*7:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1;
    CData/*6:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_character_read;
    SData/*9:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter;
    SData/*13:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse;
    CData/*3:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send;
    CData/*4:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    CData/*4:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    IData/*31:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    IData/*31:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    // Body
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 = 0U;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1 = 0U;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_access_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand2 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand1 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__operation 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__operation;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__state;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__program_rom_address 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 = 0U;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_character_read 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_read;
    vlSelf->__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v0 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v1 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v2 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v3 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v4 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v5 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v6 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v7 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v8 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v9 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v10 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v11 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v12 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v14 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v16 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v18 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v19 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v20 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v21 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v22 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v23 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v24 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v25 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v26 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v27 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v28 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v29 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v30 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v31 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v32 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v33 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v35 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v36 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v37 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v38 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v40 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v42 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v44 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v45 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v47 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v48 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v49 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v58 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v59 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v60 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v61 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v62 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v63 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v64 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v65 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v66 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v67 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v68 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v70 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v71 = 0U;
    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v72 = 0U;
    verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hf5b3c59a__0 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient;
    if ((0x10U >= (0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))) {
        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 
            = verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hf5b3c59a__0;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 = 1U;
        __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0 
            = (0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr);
        verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hc49af5e7__0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain;
        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 
            = verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hc49af5e7__0;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 = 1U;
        __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0 
            = (0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr);
    } else {
        verilator_test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound_hc49af5e7__0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain;
    }
    __Vdly__verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = VL_MODDIVS_III(32, ((IData)(1U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr), (IData)(0xfU));
    if (vlSelf->reset_n) {
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
                = (7U & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
                = (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size) 
                         - (IData)(1U)));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready) 
             & (~ ((5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound_h641c722f__0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode;
            if ((4U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))) {
                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound_h641c722f__0;
                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer;
            }
            vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer 
                = ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer))));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size) 
                           - (IData)(1U)));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_full)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size)));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_empty)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
                = (0xfU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1 = 1U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size = 0U;
    }
    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable) {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_character_read 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound_hc18ac365__0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write;
        if ((0x3ecfU >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access))) {
            vlSelf->__Vdlyvval__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound_hc18ac365__0;
            vlSelf->__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 1U;
            vlSelf->__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access;
        }
    } else {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_character_read 
            = ((0x3ecfU >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access))
                ? vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer
               [vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access]
                : 0U);
    }
    if (vlSelf->reset_n) {
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write) 
             & (~ ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound_ha352e82a__0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in;
            if ((9U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))) {
                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound_ha352e82a__0;
                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer;
            }
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer 
                = ((9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer))));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write) 
             & (~ ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound_ha352e82a__0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in;
            if ((9U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))) {
                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound_ha352e82a__0;
                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 = 1U;
                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer;
            }
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer 
                = ((9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer))));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state) 
             & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state)))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
                = (0x7ffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register) 
                             >> 1U));
            __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
                = (0x200U | (IData)(__Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register));
            __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter)));
            if ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter))) {
                if (((1U & (~ VL_REDXOR_32((0x1ffU 
                                            & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register) 
                                               >> 1U))))) 
                     == (1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register) 
                               >> 0xaU)))) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode 
                        = (0xffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register) 
                                    >> 1U));
                }
                __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter = 0U;
            }
        } else {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready = 0U;
        }
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1 = 1U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1 = 1U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter = 0U;
    }
    if (vlSelf->reset_n) {
        if (((((((((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state)) 
                   | (1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
                  | (2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
                 | (3U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
                | (4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
               | (5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
              | (6U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) 
             | (7U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state)))) {
            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if (VL_UNLIKELY(((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done) 
                                 & (0x14U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter))))) {
                    VL_WRITEF("%t: Changing state to STATE_LOAD_TO_RAM\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 1U;
                } else if (VL_UNLIKELY(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done)) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter)));
                    VL_WRITEF("%t: Init_done is done. Counter is %3#.\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,8,(IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter));
                } else {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 0U;
                }
            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if (VL_UNLIKELY(vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_done)) {
                    VL_WRITEF("%t: Changing state to STATE_FETCH_OPERATION\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9);
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                        = ((IData)(4U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address);
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v0 
                        = ((IData)(4U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address);
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v0 = 1U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 2U;
                } else {
                    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state))))) {
                        __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data 
                            = vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_byte;
                        __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address 
                            = (0x3fffffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address);
                        VL_WRITEF("program_rom_address: %10#\n",
                                  32,vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address);
                        if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state 
                                = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                    ? 0U : 1U);
                        } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_address;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__0__ram_write_data;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                        } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                        }
                        VL_WRITEF("program_rom_byte: %3#\n",
                                  8,vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_byte);
                    }
                    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete) {
                        if ((4U > vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address)) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_byte) 
                                    << 0x18U) | (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                                 >> 8U));
                        }
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__program_rom_address 
                            = ((IData)(1U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address);
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state = 1U;
                    } else {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state = 0U;
                    }
                }
            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address 
                    = (0x3fffffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                       [0U]);
                if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                        = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                        = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                            ? 0U : 1U);
                } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                        = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__1__ram_read_address;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                    }
                }
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operation 
                        = (0xffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data));
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 3U;
                } else {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 2U;
                }
            } else if ((3U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 4U;
                } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand1 
                        = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data) 
                            << 0x18U) | (vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1 
                                         >> 8U));
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                } else {
                    __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address 
                        = (0x3fffffU & ((IData)(1U) 
                                        + (vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                           [0U] + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))));
                    if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                            = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                            = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                ? 0U : 1U);
                    } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                            = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__2__ram_read_address;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                    } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                        }
                    }
                }
            } else if ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 5U;
                } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__operand2 
                        = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data) 
                            << 0x18U) | (vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2 
                                         >> 8U));
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                } else {
                    __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address 
                        = (0x3fffffU & ((IData)(5U) 
                                        + (vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                           [0U] + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))));
                    if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                            = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                            = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                ? 0U : 1U);
                    } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                            = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__3__ram_read_address;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                    } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                        }
                    }
                }
            } else if ((5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if (((((((((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)) 
                           | (1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                          | (0x11U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                         | (0x13U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                        | (2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                       | (0x12U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                      | (3U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                     | (4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                    if (VL_UNLIKELY((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("NOP\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v1 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v1 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if (VL_UNLIKELY((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                            VL_WRITEF("LOAD\nLoaded value %0# from address %0# in RAM to register %0#.\n",
                                      32,((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U),32,
                                      vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1,
                                      32,vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v2 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v2 = 1U;
                        } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__0 
                                = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data) 
                                    << 0x18U) | (((9U 
                                                   >= 
                                                   (0xfU 
                                                    & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                   ? 
                                                  vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                  [
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                   : 0U) 
                                                 >> 8U));
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v3 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__0;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v3 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v3 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            }
                        } else {
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address 
                                = (0x3fffffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__6__ram_read_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                }
                            }
                        }
                    } else if ((0x11U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__1 
                                = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data) 
                                    << 0x18U) | (((9U 
                                                   >= 
                                                   (0xfU 
                                                    & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                   ? 
                                                  vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                  [
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                   : 0U) 
                                                 >> 8U));
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v4 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__1;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v4 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v4 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            }
                        } else if (VL_UNLIKELY((4U 
                                                == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                            VL_WRITEF("RLOAD\nLoaded value %0# from address %0# in RAM to register %0#.\n",
                                      32,((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U),32,
                                      vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address,
                                      32,vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v5 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v5 = 1U;
                        } else if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                    : 0U);
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address 
                                = (0x3fffffU & (((9U 
                                                  >= 
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                  ? 
                                                 vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                 [(0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                  : 0U) 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__8__ram_read_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                }
                            }
                        } else {
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address 
                                = (0x3fffffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__9__ram_read_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                                }
                            }
                        }
                    } else if (VL_UNLIKELY((0x13U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("CLOAD\n");
                        vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__2 
                            = vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1;
                        if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v6 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__2;
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v6 = 1U;
                            __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v6 
                                = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                        }
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v7 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v7 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if (VL_UNLIKELY((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                            VL_WRITEF("STORE\n");
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v8 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v8 = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__0 
                                = ((((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                      ? (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                         [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                      : 0U) << 0x18U) 
                                   | (((9U >= (0xfU 
                                               & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                        ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                        : 0U) >> 8U));
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v9 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__0;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v9 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v9 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1);
                            }
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                        } else {
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                    : 0U);
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address 
                                = (0x3fffffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__12__ram_write_data;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                            }
                        }
                    } else if ((0x12U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if (VL_UNLIKELY((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                            VL_WRITEF("RSTORE\n");
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v10 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v10 = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__1 
                                = ((((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                      ? (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                         [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                      : 0U) << 0x18U) 
                                   | (((9U >= (0xfU 
                                               & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                        ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                        : 0U) >> 8U));
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v11 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__1;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v11 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v11 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1);
                            }
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                        } else if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index))) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                    : 0U);
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                    : 0U);
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address 
                                = (0x3fffffU & (((9U 
                                                  >= 
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                  ? 
                                                 vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                 [(0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                  : 0U) 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__14__ram_write_data;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                            }
                        } else {
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                    : 0U);
                            __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address 
                                = (0x3fffffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address 
                                                + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state 
                                    = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                        ? 0U : 1U);
                            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_address;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i 
                                    = __Vtask_verilator_test__DOT__top_instantiation__DOT__write_to_ram__15__ram_write_data;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 2U;
                            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state))) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 0U;
                            }
                        }
                    } else if ((3U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        VL_WRITEF("ADD\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v12 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) + ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v12 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v13 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else {
                        VL_WRITEF("SUB\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v14 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) - ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v14 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v15 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    }
                } else if (((((((((0x14U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)) 
                                  | (0x15U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                                 | (5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                                | (6U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                               | (7U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                              | (8U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                             | (9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                            | (0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("MULT\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v16 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) * ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v16 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v17 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((0x15U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter))) {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter 
                                = (0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter)));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_numerator 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                    : 0U);
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_denominator 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                    : 0U);
                        } else if (VL_UNLIKELY((0x10U 
                                                == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter)))) {
                            VL_WRITEF("DIV\n");
                            if ((0x10U >= (0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v18 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe
                                    [(0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)];
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v18 = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter = 0U;
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v19 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe
                                    [(0x1fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)];
                            } else {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v18 = 0U;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v18 = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter = 0U;
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v19 = 0U;
                            }
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v19 = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v20 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v20 = 1U;
                        } else {
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter 
                                = (0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter)));
                        }
                    } else if ((5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if (VL_UNLIKELY(((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_access_state)) 
                                         & (0x3ed0U 
                                            > ((9U 
                                                >= 
                                                (0xfU 
                                                 & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                               [(0xfU 
                                                 & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                : 0U))))) {
                            VL_WRITEF("\033[1;32mOUT [address %0#, character '%c' (integer value %0#)]\033[0m\n",
                                      32,((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                           : 0U),32,
                                      ((9U >= (0xfU 
                                               & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                        ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                        : 0U),32,((9U 
                                                   >= 
                                                   (0xfU 
                                                    & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                   ? 
                                                  vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                  [
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                   : 0U));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? (0x3fffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                    : 0U);
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                    ? (0x7fU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)])
                                    : 0U);
                        } else if (VL_UNLIKELY((0x3ed0U 
                                                == 
                                                ((9U 
                                                  >= 
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                  ? 
                                                 vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                 [(0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                  : 0U)))) {
                            VL_WRITEF("Error: CPU cannot write to interrupt value port.\n");
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v21 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v21 = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        } else if ((0x3ed1U == ((9U 
                                                 >= 
                                                 (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                 ? 
                                                vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                [(0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                 : 0U))) {
                            if (VL_LIKELY(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state)) {
                                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state) {
                                    __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse = 0U;
                                    if (VL_UNLIKELY(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done)) {
                                        VL_WRITEF("Finish SPI write...\n");
                                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v22 
                                            = ((IData)(9U) 
                                               + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                               [0U]);
                                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v22 = 1U;
                                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state = 0U;
                                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                                    }
                                }
                            } else {
                                VL_WRITEF("\033[1;32mOUT [SPI, address %0#, value %0#]\033[0m\nStart SPI write...\n",
                                          32,((9U >= 
                                               (0xfU 
                                                & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                               ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                              [(0xfU 
                                                & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                               : 0U),
                                          32,((9U >= 
                                               (0xfU 
                                                & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                               ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                              [(0xfU 
                                                & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                               : 0U));
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse = 1U;
                                vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send 
                                    = ((9U >= (0xfU 
                                               & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                        ? (0xffU & 
                                           vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                           [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)])
                                        : 0U);
                            }
                        } else if (VL_UNLIKELY((0x3ed2U 
                                                == 
                                                ((9U 
                                                  >= 
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                  ? 
                                                 vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                 [(0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                  : 0U)))) {
                            VL_WRITEF("\033[1;32mOUT [SPI CS, address %0#, value %0#]\033[0m\n",
                                      32,((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                           : 0U),32,
                                      ((9U >= (0xfU 
                                               & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                        ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                        : 0U));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select 
                                = (0U != ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v23 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v23 = 1U;
                        } else {
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v24 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v24 = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        }
                    } else if (VL_UNLIKELY((6U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("IN\n");
                        if (((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_access_state)) 
                             & (0x3ed0U > ((9U >= (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                            ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                           [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                            : 0U)))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? (0x3fffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                       [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                    : 0U);
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state = 1U;
                        } else if ((0x3ed0U == ((9U 
                                                 >= 
                                                 (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                 ? 
                                                vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                [(0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                 : 0U))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__3 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out;
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v25 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__3;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v25 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v25 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            }
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v26 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v26 = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        } else if ((0x3ed1U == ((9U 
                                                 >= 
                                                 (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                                 ? 
                                                vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                [(0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                                 : 0U))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__4 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received;
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v27 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__4;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v27 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v27 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            }
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v28 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v28 = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        } else {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__5 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_read;
                            if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                                __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v29 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__5;
                                __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v29 = 1U;
                                __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v29 
                                    = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                            }
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v30 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v30 = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        }
                    } else if (VL_UNLIKELY((7U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("MOV\n");
                        vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__6 
                            = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                : 0U);
                        if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))) {
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v31 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__6;
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v31 = 1U;
                            __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v31 
                                = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2);
                        }
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v32 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v32 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if (VL_UNLIKELY((8U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("CMP register %0# (value %0#), register %0# (value %0#)\n",
                                  32,vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1,
                                  32,((9U >= (0xfU 
                                              & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                       ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                      [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                       : 0U),32,vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2,
                                  32,((9U >= (0xfU 
                                              & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                       ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                      [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                       : 0U));
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v33 
                            = ((((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                  ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                 [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                  : 0U) < ((9U >= (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                            ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                           [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                            : 0U)) ? 0U
                                : ((((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                      ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                     [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                      : 0U) == ((9U 
                                                 >= 
                                                 (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                 ? 
                                                vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                [(0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                 : 0U))
                                    ? 1U : 2U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v33 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v34 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        VL_WRITEF("JMPL\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v35 
                            = ((0U == vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [1U]) ? (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                         + vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)
                                : ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v35 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else {
                        VL_WRITEF("JMPE\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v36 
                            = ((1U == vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [1U]) ? (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                         + vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)
                                : ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v36 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    }
                } else if (((((((((0xbU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)) 
                                  | (0x16U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                                 | (0x17U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                                | (0x18U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                               | (0x19U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                              | (0xeU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                             | (0xfU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) 
                            | (0xcU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                    if (VL_UNLIKELY((0xbU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("JMPG\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v37 
                            = ((2U == vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [1U]) ? (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                         + vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)
                                : ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v37 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((0x16U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v38 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) | ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v38 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v39 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((0x17U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v40 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) & ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v40 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v41 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((0x18U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v42 
                            = (((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                 ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                 : 0U) ^ ((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                           : 0U));
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v42 = 1U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v43 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if ((0x19U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__2 
                            = (~ ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                   ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                  [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                   : 0U));
                        if ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))) {
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v44 
                                = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__2;
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v44 = 1U;
                            __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v44 
                                = (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1);
                        }
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v45 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v45 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    } else if (VL_UNLIKELY((0xeU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                        VL_WRITEF("ISR\nSetting interrupt No. %10# to address %10#.\n",
                                  32,((9U >= (0xfU 
                                              & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                       ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                      [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                       : 0U),32,((9U 
                                                  >= 
                                                  (0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                                  ? 
                                                 vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                                 [(0xfU 
                                                   & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                                  : 0U));
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 
                            = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2))
                                ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2)]
                                : 0U);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 = 1U;
                        __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0 
                            = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                ? (7U & vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)])
                                : 0U);
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v46 
                            = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                               [0U]);
                    } else if ((0xfU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation))) {
                        if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))) {
                            VL_WRITEF("Triggering interrupt No. %10#.\n",
                                      32,((9U >= (0xfU 
                                                  & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                           ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                          [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                           : 0U));
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in 
                                = ((9U >= (0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1))
                                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [(0xfU & vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1)]
                                    : 0U);
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = 1U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 2U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in = 0U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 1U;
                        } else {
                            VL_WRITEF("INT\n");
                            __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v47 
                                = ((IData)(9U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                   [0U]);
                            __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v47 = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        }
                    } else if (VL_UNLIKELY((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)))) {
                        VL_WRITEF("RST\n");
                        __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v48 
                            = ((IData)(4U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address);
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v48 = 1U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                            = ((IData)(4U) + vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address);
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v49 = 1U;
                    } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete) {
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                            = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data) 
                                << 0x18U) | (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                                             >> 8U));
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index)));
                        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
                    } else {
                        __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__35__ram_read_address 
                            = vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index;
                        if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__35__ram_read_address;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state 
                                = ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))
                                    ? 0U : 1U);
                        } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i 
                                = __Vtask_verilator_test__DOT__top_instantiation__DOT__read_from_ram__35__ram_read_address;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 0U;
                            __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 2U;
                        } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state))) {
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
                            if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o) {
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 1U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
                                __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data 
                                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
                            }
                        }
                    }
                } else if (VL_UNLIKELY((0x10U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                    VL_WRITEF("ENDINT\n");
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [0U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v58 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v58 = 1U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 6U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [1U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v59 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v59 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [2U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v60 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v60 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [3U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v61 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v61 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [4U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v62 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v62 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [5U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v63 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v63 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [6U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v64 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v64 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [7U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v65 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v65 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [8U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v66 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v66 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers
                        [9U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v67 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v67 = 1U;
                } else if (VL_UNLIKELY((0xdU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__operation)))) {
                    VL_WRITEF("HALT\n");
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 5U;
                    VL_FINISH_MT("alu/alu.v", 366, "");
                }
            } else if ((6U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__state))) {
                if (((0U != vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                      [9U]) | (((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                 ? 1U : 0U) & (0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 7U;
                } else if ((((0U != (~ vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                                     [9U])) & (~ ((0U 
                                                   == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                                   ? 1U
                                                   : 0U))) 
                            & (0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state)))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read = 1U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 1U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 1U;
                } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 2U;
                } else if (VL_UNLIKELY((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state)))) {
                    VL_WRITEF("interrupt_fifo_data_out: %10#\n",
                              32,vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out);
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v68 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [0U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0 = 1U;
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v69 
                        = (vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
                           + vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table
                           [(7U & vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out)]);
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 7U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [1U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [2U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [3U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [4U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [5U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [6U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [7U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [8U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8 = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                        [9U];
                    __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
                    __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9 = 1U;
                }
            } else if (((0U == vlSelf->verilator_test__DOT__top_instantiation__DOT__registers
                         [8U]) | (((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                    ? 1U : 0U) & (0U 
                                                  == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 2U;
            } else if (((~ ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                             ? 1U : 0U)) & (0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state)))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 1U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 1U;
            } else if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 0U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 2U;
            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = 1U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in = 0U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 1U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 3U;
            } else if ((3U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 0U;
            }
        }
    } else {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__operand1 = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__operand2 = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v70 = 1U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = 1U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = 1U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__program_rom_address = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__state = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__operation = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v71 = 1U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_numerator = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_denominator = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state = 0U;
        __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v72 = 1U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_read 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_character_read;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__code_section_start_address;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_complete;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_write_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_data;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ram_read_complete;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operation 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__operation;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__operand_byte_index;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__operand1;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__operand2;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__temp_address;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__division_delay_counter;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_access_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__gpu_access_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v71) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[0U] = 0U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v72) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[1U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[4U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[5U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[6U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[7U] = 0U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v1;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[2U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v2;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[3U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v3;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[4U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v4;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[5U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v5;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[6U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v6;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[7U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v7;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[8U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v8;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[9U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v9;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v1) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v1;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v2) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v2;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v3) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v3] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v3;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v4) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v4] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v4;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v5) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v5;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v6) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v6] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v6;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v7) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v7;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v8) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v8;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v9) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v9] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v9;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v10) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v10;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v11) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v11] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v11;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v12) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v12;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v13;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v14) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v14;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v15;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v16) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v16;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v17;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v18) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v18;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v19) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[2U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v19;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v20) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v20;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v21) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v21;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v22) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v22;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v23) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v23;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v24) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v24;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v25) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v25] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v25;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v26) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v26;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v27) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v27] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v27;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v28) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v28;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v29) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v29] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v29;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v30) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v30;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v31) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v31] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v31;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v32) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v32;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v33) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v33;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v34;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v35) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v35;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v36) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v36;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v37) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v37;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v38) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v38;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v39;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v40) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v40;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v41;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v42) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v42;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v43;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v44) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__registers__v44] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v44;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v45) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v45;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v46;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v47) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v47;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v48) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v48;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v49) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[4U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[5U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[6U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[7U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[8U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[9U] = 0U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v58) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v58;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v59) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v59;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v60) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[2U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v60;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v61) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[3U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v61;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v62) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[4U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v62;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v63) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[5U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v63;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v64) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[6U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v64;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v65) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[7U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v65;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v66) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[8U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v66;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v67) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[9U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v67;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v68) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[9U] = 1U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__shadow_registers__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__registers__v69;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v70) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[0U] = 0U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v71) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[1U] = 0U;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__registers__v72) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[4U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[5U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[6U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[7U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[8U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[9U] = 0U;
    }
    if (vlSelf->reset_n) {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer 
            = (0x80U | (0x7fU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer) 
                                 >> 1U)));
        if ((0xffU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
            __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state = 1U;
        } else if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
            __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state = 0U;
        }
    } else {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer = 0xffU;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state = 1U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state = 1U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_byte 
        = ((0xdd7U >= (0xfffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address))
            ? vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom__DOT__rom_memory
           [(0xfffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address)]
            : 0U);
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_numerator;
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_denominator;
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q 
        = VL_DIV_III(32, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r 
        = VL_MODDIV_III(32, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient 
        = verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain 
        = verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r;
    if (vlSelf->reset_n) {
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read) 
             & (~ ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out 
                = ((9U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))
                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items
                   [vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer]
                    : 0U);
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer 
                = ((9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer))));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read) 
             & (~ ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out 
                = ((9U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))
                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items
                   [vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer]
                    : 0U);
            vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer 
                = ((9U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer))));
        }
        if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read) 
             & (~ ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                    ? 1U : 0U)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out 
                = ((4U >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))
                    ? vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items
                   [vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer]
                    : 0U);
            vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer 
                = ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer))));
        }
        __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse 
            = (0x3fffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse)));
        if ((0U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send))) {
            if (vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling) {
                vlSelf->verilator_test__DOT__spi_sclk = 0U;
                vlSelf->verilator_test__DOT__spi_copi 
                    = (1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send) 
                             >> (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send) 
                                       - (IData)(1U)))));
            } else if ((((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock)) 
                         & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock)) 
                        & (0xfaU <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse)))) {
                vlSelf->verilator_test__DOT__spi_sclk = 1U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received 
                    = (((~ ((IData)(1U) << (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send) 
                                                  - (IData)(1U))))) 
                        & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received)) 
                       | (0xffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__SD_DAT) 
                                   << (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send) 
                                             - (IData)(1U))))));
                __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send 
                    = (0xfU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send) 
                               - (IData)(1U)));
                if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send))) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done = 1U;
                }
            }
        } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send = 8U;
            __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse = 0U;
            vlSelf->verilator_test__DOT__spi_copi = 
                (1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send) 
                       >> 7U));
        } else if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send))) {
            if (vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling) {
                vlSelf->verilator_test__DOT__spi_sclk = 0U;
            }
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done = 0U;
        }
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse = 0U;
        vlSelf->verilator_test__DOT__spi_sclk = 0U;
        vlSelf->verilator_test__DOT__spi_copi = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__program_rom_address;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items__v1) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[0U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[1U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[4U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[5U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[6U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[7U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[8U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[9U] = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read;
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items__v1) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[0U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[1U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[4U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[5U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[6U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[7U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[8U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[9U] = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0] 
            = __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v0;
    }
    if (__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items__v1) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[0U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[1U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[2U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[3U] = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[4U] = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_done 
        = (0xdd7U == vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full 
        = ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_full 
        = ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full 
        = ((5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    if (vlSelf->reset_n) {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter)));
        vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock;
        if ((0x1f4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock 
                = (1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock)));
            __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter = 0U;
        }
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock) 
           & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock)));
}

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__3(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__3\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h4c87eb7c__0;
    // Body
    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking) {
        vlSelf->verilator_test__DOT__VGA_B = 0U;
        vlSelf->verilator_test__DOT__VGA_G = 0U;
        vlSelf->verilator_test__DOT__VGA_R = 0U;
    } else if (vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value) {
        vlSelf->verilator_test__DOT__VGA_B = 0xfU;
        vlSelf->verilator_test__DOT__VGA_G = 0xfU;
        vlSelf->verilator_test__DOT__VGA_R = 0xfU;
    } else {
        vlSelf->verilator_test__DOT__VGA_B = 0U;
        vlSelf->verilator_test__DOT__VGA_G = 0U;
        vlSelf->verilator_test__DOT__VGA_R = 0U;
    }
    __Vtemp_h4c87eb7c__0[0U] = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][0U];
    __Vtemp_h4c87eb7c__0[1U] = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][1U];
    __Vtemp_h4c87eb7c__0[2U] = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][2U];
    __Vtemp_h4c87eb7c__0[3U] = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage
        [vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character][3U];
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value 
        = ((0x7fU >= (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                       << 3U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) 
           & (__Vtemp_h4c87eb7c__0[(3U & (((IData)(0x7fU) 
                                           - (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                                               << 3U) 
                                              + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) 
                                          >> 5U))] 
              >> (0x1fU & ((IData)(0x7fU) - (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y) 
                                              << 3U) 
                                             + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character 
        = ((0x3ecfU >= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell))
            ? vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer
           [vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell]
            : 0U);
}

extern const VlUnpacked<CData/*2:0*/, 512> Vverilator_test__ConstPool__TABLE_h844f83a3_0;
extern const VlUnpacked<CData/*1:0*/, 512> Vverilator_test__ConstPool__TABLE_h52aef0e4_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vverilator_test__ConstPool__TABLE_h2d134a92_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vverilator_test__ConstPool__TABLE_h1e913406_0;

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__4(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__4\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    // Body
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
    if (vlSelf->reset_n) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o 
            = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid) 
               >> 2U);
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
            = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter))
                ? 0x30dU : (0x1fffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter) 
                                       - (IData)(1U))));
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done 
            = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done) 
               | (5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state)));
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o 
            = vlSelf->verilator_test__DOT__DRAM_DQ;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
            = ((((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter)) 
                 | (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)) 
                & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request))) 
               & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done));
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid 
            = (7U & (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid) 
                      << 1U) | (5U == (7U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))));
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o = 0U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter = 0x1388U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o = 0U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) 
                     << 8U) | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty) 
                                << 7U) | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) 
                                           << 6U) | 
                                          (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries) 
                                            << 4U) 
                                           | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o) 
                                               << 3U) 
                                              | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->reset_n))))))));
    if ((1U & Vverilator_test__ConstPool__TABLE_h844f83a3_0
         [__Vtableidx1])) {
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
            = Vverilator_test__ConstPool__TABLE_h52aef0e4_0
            [__Vtableidx1];
    }
    if ((2U & Vverilator_test__ConstPool__TABLE_h844f83a3_0
         [__Vtableidx1])) {
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
            = Vverilator_test__ConstPool__TABLE_h2d134a92_0
            [__Vtableidx1];
    }
    if ((4U & Vverilator_test__ConstPool__TABLE_h844f83a3_0
         [__Vtableidx1])) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address 
            = Vverilator_test__ConstPool__TABLE_h1e913406_0
            [__Vtableidx1];
    }
}

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__5(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__5\n"); );
    // Init
    SData/*13:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    CData/*7:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    CData/*3:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    SData/*11:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    SData/*12:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    // Body
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    if (VL_LIKELY(vlSelf->reset_n)) {
        if ((1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking)))) {
            if ((0xf0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column))) {
                if ((0xfU != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y))) {
                    __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
                        = (0x3fffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell) 
                                      - (IData)(0xf0U)));
                }
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column = 0U;
            } else if ((7U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column)));
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
                    = (0x3fffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell)));
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
            } else {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x)));
            }
            if (((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x)) 
                 & (0U == ((0x438U <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))
                            ? 0x437U : (0x7ffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell = 0U;
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y = 0U;
            } else if ((0x780U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x))) {
                __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y)));
            }
        }
    } else {
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell = 0U;
        VL_WRITEF("In reset.\n");
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column = 0U;
    }
    if (VL_LIKELY(vlSelf->reset_n)) {
        if ((0x898U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
                = (0xfffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)));
            __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count = 0U;
        } else {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
                = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)));
        }
        if ((0x465U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))) {
            __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count = 0U;
        }
    } else {
        VL_WRITEF("Resetting...\n");
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count = 0U;
        __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count 
        = __Vdly__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x 
        = ((0x118U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count))
            ? 0U : (0xfffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count) 
                              - (IData)(0x118U))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking 
        = ((0x118U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
           | (0x437U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)));
}

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__6(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__6\n"); );
    // Init
    IData/*21:0*/ __Vdlyvdim0__verilator_test__DOT__sdram_module__DOT__mem_array__v0;
    SData/*15:0*/ __Vdlyvval__verilator_test__DOT__sdram_module__DOT__mem_array__v0;
    CData/*0:0*/ __Vdlyvset__verilator_test__DOT__sdram_module__DOT__mem_array__v0;
    // Body
    __Vdlyvset__verilator_test__DOT__sdram_module__DOT__mem_array__v0 = 0U;
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2 
        = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1;
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe 
        = ((6U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe) 
                  << 1U)) | (0x205244U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE));
    if (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr) 
         & (2U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)))) {
        if ((1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address)))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
        }
        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) {
            if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
            }
        }
    }
    if ((0x205752U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE)) {
        __Vdlyvval__verilator_test__DOT__sdram_module__DOT__mem_array__v0 
            = ((0xff00U & (((2U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))
                             ? ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data) 
                                >> 8U) : ((IData)(vlSelf->verilator_test__DOT__DRAM_DQ) 
                                          >> 8U)) << 8U)) 
               | (0xffU & ((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))
                            ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data)
                            : (IData)(vlSelf->verilator_test__DOT__DRAM_DQ))));
        __Vdlyvset__verilator_test__DOT__sdram_module__DOT__mem_array__v0 = 1U;
        __Vdlyvdim0__verilator_test__DOT__sdram_module__DOT__mem_array__v0 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr;
    }
    if ((0x4c4d52U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE)) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__latency 
            = (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr) 
                     >> 4U));
    }
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2 
        = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1;
    if ((0x414354U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE)) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__addr_crb 
            = ((0x2000U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                           << 0xcU)) | (((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr) 
                                         << 1U) | (1U 
                                                   & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
    }
    if (__Vdlyvset__verilator_test__DOT__sdram_module__DOT__mem_array__v0) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__mem_array[__Vdlyvdim0__verilator_test__DOT__sdram_module__DOT__mem_array__v0] 
            = __Vdlyvval__verilator_test__DOT__sdram_module__DOT__mem_array__v0;
    }
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1 
        = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0;
    if ((0U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                      - (IData)(1U))))) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid 
            = (1U & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe));
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0;
    } else if ((1U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                             - (IData)(1U))))) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid 
            = (1U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe) 
                     >> 1U));
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1;
    } else {
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid 
            = (1U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe) 
                     >> 2U));
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr;
        vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
        vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask 
            = vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2;
    }
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1 
        = ((((2U & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
              ? 0U : 0xffU) << 8U) | ((1U & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                       ? 0U : 0xffU));
    vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0 
        = ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid)
            ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1)
            : 0U);
}

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__8(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__8\n"); );
    // Body
    if (vlSelf->__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer[vlSelf->__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0] 
            = vlSelf->__Vdlyvval__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data 
        = (((QData)((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            << 0x28U) | (((QData)((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i)) 
                          << 0x12U) | (QData)((IData)(
                                                      ((((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)
                                                          ? 0U
                                                          : (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i)) 
                                                        << 0x10U) 
                                                       | (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i))))));
}

VL_INLINE_OPT void Vverilator_test___024root___sequent__TOP__9(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___sequent__TOP__9\n"); );
    // Body
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
    if (vlSelf->reset_n) {
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
        if (((((((((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state)) 
                   | (2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                  | (4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                 | (8U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
                | (0x10U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
               | (0x20U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
              | (0x40U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) 
             | (0x80U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state)))) {
            if ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done) {
                    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 7U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 0U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x40U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 0x80U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 1U;
                    } else {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 0xfU;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 0U;
                        if ((0U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))) {
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                                = (1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x28U)));
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                = (0x3fffffU & (IData)(
                                                       (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                        >> 0x12U)));
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                                = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                                = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x10U)));
                            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 2U;
                        }
                    }
                } else {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 1U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd;
                }
            } else if ((2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = (3U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                             << 3U));
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                    = (0xfffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                 >> 9U));
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
                    = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw)
                        ? 8U : 0x10U);
            } else if ((4U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = ((0x80U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next))
                        ? 7U : (7U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                      << 3U)));
                if ((1U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count))) {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
                        = (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count) 
                                 - (IData)(1U)));
                } else {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
                }
            } else if ((8U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = (5U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                             << 3U));
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                        = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x10U)));
                } else {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                        = (3U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm));
                }
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending) {
                    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 2U;
                    } else {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                            = (1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                             >> 0x28U)));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                            = (0x3fffffU & (IData)(
                                                   (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x12U)));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                            = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                            = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                             >> 0x10U)));
                    }
                } else {
                    if (((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending)) 
                         & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                            = (7U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                     << 3U));
                    }
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x100U;
                }
            } else if ((0x10U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = (4U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                             << 3U));
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                        = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                        = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x10U)));
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
                } else {
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data 
                        = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data));
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm 
                        = (3U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm));
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
                }
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr 
                    = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 1U;
                if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending) {
                    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                    } else {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
                            = (1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                             >> 0x28U)));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                            = (0x3fffffU & (IData)(
                                                   (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x12U)));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                            = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                            = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                             >> 0x10U)));
                    }
                } else {
                    if (((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending)) 
                         & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop))) {
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                            = (7U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                     << 3U));
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
                    }
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x100U;
                }
            } else if ((0x20U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = (7U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                             << 3U));
                if ((1U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count))) {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
                        = (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count) 
                                 - (IData)(1U)));
                } else {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x40U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
                }
            } else if ((0x40U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr = 0xfffU;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                    = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request)
                        ? 2U : (2U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                                      << 3U)));
            } else {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 1U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 1U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 3U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
            }
        } else if ((0x100U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state))) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd 
                = (7U | ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n) 
                         << 3U));
            if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request) {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 4U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
            } else if ((0U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))) {
                if (((((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match) 
                       & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match)) 
                      & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match)) 
                     & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match))) {
                    if ((1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                       >> 0x28U)))) {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 8U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw = 1U;
                    } else {
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x10U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 1U;
                        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = 0U;
                        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw = 0U;
                    }
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                        = (0x3fffffU & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                >> 0x12U)));
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
                        = (0xffffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data));
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
                        = (3U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x10U)));
                } else {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 0x20U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 1U;
                }
            }
        } else {
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 0xfU;
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
        }
    } else {
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = 0U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = 1U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = 1U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = 0xfU;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm = 0U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1;
        }
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0;
    }
    vlSelf->verilator_test__DOT__sdram_module__DOT__CODE 
        = ((8U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))
            ? 0x494e48U : ((0U == (7U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                            ? 0x4c4d52U : ((1U == (7U 
                                                   & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x415246U
                                            : ((2U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x505245U
                                                : (
                                                   (3U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x414354U
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x205752U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x205244U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                       ? 0x425354U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                        ? 0x4e4f50U
                                                        : 0x424144U)))))))));
    vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr 
        = (((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__addr_crb) 
            << 8U) | (0xffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr)));
    if (vlSelf->reset_n) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0xfffU;
        if ((4U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
            if ((2U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                if ((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0U;
                    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0x30U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 4U;
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 5U;
                } else {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 0U;
                }
            } else {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
                    = ((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))
                        ? 5U : 0U);
            }
        } else if ((2U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
            if ((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 7U;
                if ((1U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count))) {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
                        = (7U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count) 
                                 - (IData)(1U)));
                } else {
                    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
                        = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
                }
            } else {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs)));
                vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 1U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 3U;
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
                    = ((1U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs))
                        ? 7U : 2U);
            }
        } else if ((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state))) {
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 3U;
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 2U;
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 0U;
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 2U;
        } else {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0xfU;
            vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs = 0U;
            if ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter))) {
                vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 1U;
            }
        }
    } else {
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = 0U;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = 0U;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = 0xfU;
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = 0xfffU;
        vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = 0U;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match 
        = (1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o 
        = (2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty 
        = (0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank 
        = ((2U & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                  >> 0x14U)) | (1U & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                      >> 8U)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw) 
           == (1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                             >> 0x28U))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match 
        = ((0xfffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                      >> 9U)) == (0xfffU & (IData)(
                                                   (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x1bU))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank 
        = ((2U & ((IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                           >> 0x27U)) << 1U)) | (1U 
                                                 & (IData)(
                                                           (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                            >> 0x1aU))));
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_data 
        = vlSelf->verilator_test__DOT__sdram_module__DOT__mem_array
        [((0x205752U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE)
           ? vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr
           : ((0U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                            - (IData)(1U)))) ? vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0
               : ((1U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                                - (IData)(1U)))) ? vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1
                   : vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2)))];
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter 
        = vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank) 
           == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank));
    vlSelf->verilator_test__DOT__DRAM_DQ = (((((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid)
                                                ? (
                                                   ((((2U 
                                                       & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                                       ? 0U
                                                       : 
                                                      (0xffU 
                                                       & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data) 
                                                          >> 8U))) 
                                                     << 8U) 
                                                    | ((1U 
                                                        & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                                        ? 0U
                                                        : 
                                                       (0xffU 
                                                        & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data)))) 
                                                   & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1))
                                                : 0U) 
                                              & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                             & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                            | (((((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                   ? (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data)
                                                   : 0U) 
                                                 & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                     ? 0xffffU
                                                     : 0U)) 
                                                & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                    ? 0xffffU
                                                    : 0U)) 
                                               & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                   ? 0xffffU
                                                   : 0U)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending 
        = (((((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)) 
              & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match)) 
             & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match)) 
            & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match)) 
           & (0U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop) 
           & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n 
        = ((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
           & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr 
        = (0xffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)
                     ? (0xffU & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x12U)))
                     : (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr)));
}

VL_INLINE_OPT void Vverilator_test___024root___multiclk__TOP__10(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___multiclk__TOP__10\n"); );
    // Body
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr 
        = (((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            | (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i))) 
           & (2U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
}

void Vverilator_test___024root___eval(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vverilator_test___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlSelf->verilator_only_vga_pixel_clock) 
         & (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_vga_pixel_clock)))) {
        Vverilator_test___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((((~ (IData)(vlSelf->reset_n)) & (IData)(vlSelf->__Vclklast__TOP__reset_n)) 
         | ((IData)(vlSelf->verilator_only_dram_clk) 
            & (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_dram_clk))))) {
        Vverilator_test___024root___sequent__TOP__4(vlSelf);
    }
    if ((((~ (IData)(vlSelf->reset_n)) & (IData)(vlSelf->__Vclklast__TOP__reset_n)) 
         | ((IData)(vlSelf->verilator_only_vga_pixel_clock) 
            & (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_vga_pixel_clock))))) {
        Vverilator_test___024root___sequent__TOP__5(vlSelf);
    }
    if (((IData)(vlSelf->verilator_only_dram_clk) & 
         (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_dram_clk)))) {
        Vverilator_test___024root___sequent__TOP__6(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vverilator_test___024root___sequent__TOP__8(vlSelf);
    }
    if ((((~ (IData)(vlSelf->reset_n)) & (IData)(vlSelf->__Vclklast__TOP__reset_n)) 
         | ((IData)(vlSelf->verilator_only_dram_clk) 
            & (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_dram_clk))))) {
        Vverilator_test___024root___sequent__TOP__9(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if (((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
          | ((~ (IData)(vlSelf->reset_n)) & (IData)(vlSelf->__Vclklast__TOP__reset_n))) 
         | ((IData)(vlSelf->verilator_only_dram_clk) 
            & (~ (IData)(vlSelf->__Vclklast__TOP__verilator_only_dram_clk))))) {
        Vverilator_test___024root___multiclk__TOP__10(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__verilator_only_vga_pixel_clock 
        = vlSelf->verilator_only_vga_pixel_clock;
    vlSelf->__Vclklast__TOP__reset_n = vlSelf->reset_n;
    vlSelf->__Vclklast__TOP__verilator_only_dram_clk 
        = vlSelf->verilator_only_dram_clk;
}

#ifdef VL_DEBUG
void Vverilator_test___024root___eval_debug_assertions(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((vlSelf->verilator_only_dram_clk 
                     & 0xfeU))) {
        Verilated::overWidthError("verilator_only_dram_clk");}
    if (VL_UNLIKELY((vlSelf->verilator_only_vga_pixel_clock 
                     & 0xfeU))) {
        Verilated::overWidthError("verilator_only_vga_pixel_clock");}
}
#endif  // VL_DEBUG
