// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTEST_H_
#define _VTEST_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtest__Syms;
class Vtest_VerilatedVcd;


//----------

VL_MODULE(Vtest) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(dram_clk_supplied,0,0);
    VL_IN8(vga_clk_supplied,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ test__DOT__PS2_CLK;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
        CData/*3:0*/ test__DOT__VGA_R;
        CData/*3:0*/ test__DOT__VGA_G;
        CData/*3:0*/ test__DOT__VGA_B;
        CData/*2:0*/ test__DOT__sdram_module__DOT__latency;
        CData/*1:0*/ test__DOT__sdram_module__DOT__rd_mask_pipe_0;
        CData/*1:0*/ test__DOT__sdram_module__DOT__rd_mask_pipe_1;
        CData/*1:0*/ test__DOT__sdram_module__DOT__rd_mask_pipe_2;
        CData/*2:0*/ test__DOT__sdram_module__DOT__rd_valid_pipe;
        CData/*1:0*/ test__DOT__sdram_module__DOT__read_mask;
        CData/*0:0*/ test__DOT__sdram_module__DOT__read_valid;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__operation;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_write;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_empty;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_full;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_read;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo_write;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_ready;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__gpu_write_enable;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__gpu_character_to_write;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__gpu_character_read;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__gpu_access_state;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__program_rom_byte;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__program_rom_done;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__program_rom_read_state;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller_be_n_i;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_cs_i;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_valid_o;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller_init_done;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__ram_write_state;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__ram_write_complete;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__ram_read_state;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__ram_read_complete;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__ram_stabilization_counter;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__operand_byte_index;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__state;
        CData/*4:0*/ test__DOT__top_instantiation__DOT__division_delay_counter;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__done;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__other_done;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
    };
    struct {
        CData/*3:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match;
        CData/*7:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank;
        CData/*3:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending;
        CData/*2:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh;
        CData/*1:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address;
        CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
        SData/*15:0*/ test__DOT__DRAM_DQ;
        SData/*13:0*/ test__DOT__sdram_module__DOT__addr_crb;
        SData/*15:0*/ test__DOT__sdram_module__DOT__read_data;
        SData/*15:0*/ test__DOT__sdram_module__DOT__rmw_temp;
        SData/*13:0*/ test__DOT__top_instantiation__DOT__gpu_cell_to_access;
        SData/*15:0*/ test__DOT__top_instantiation__DOT__sdram_controller_data_i;
        SData/*15:0*/ test__DOT__top_instantiation__DOT__sdram_controller_data_o;
        SData/*15:0*/ test__DOT__top_instantiation__DOT__ram_read_data;
        SData/*10:0*/ test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register;
        SData/*11:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x;
        SData/*13:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
        SData/*12:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
        SData/*11:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
        SData/*15:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
        SData/*11:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr;
        SData/*11:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr;
        SData/*15:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data;
        SData/*8:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
        SData/*8:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
        SData/*12:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
        IData/*31:0*/ test__DOT__i;
        IData/*23:0*/ test__DOT__sdram_module__DOT__CODE;
        IData/*21:0*/ test__DOT__sdram_module__DOT__rd_addr_pipe_0;
        IData/*21:0*/ test__DOT__sdram_module__DOT__rd_addr_pipe_1;
        IData/*21:0*/ test__DOT__sdram_module__DOT__rd_addr_pipe_2;
        IData/*21:0*/ test__DOT__sdram_module__DOT__test_addr;
        IData/*31:0*/ test__DOT__sdram_module__DOT__i;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__i;
    };
    struct {
        IData/*31:0*/ test__DOT__top_instantiation__DOT__operand1;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__operand2;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__code_section_start_address;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__program_end_address;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__temp_address;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_data_in;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo_data_out;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__program_rom_address;
        IData/*21:0*/ test__DOT__top_instantiation__DOT__sdram_controller_address_i;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider_numerator;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider_denominator;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__i;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__i;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__i;
        IData/*21:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__not_numer;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__int_numer;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__not_denom;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__int_denom;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__t_numer;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__t_q;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__t_denom;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__t_r;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__i;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__rsig;
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
        QData/*35:0*/ test__DOT__top_instantiation__DOT__GPIO_0;
        QData/*40:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data;
        QData/*40:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0;
        QData/*40:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1;
        QData/*39:0*/ test__DOT__top_instantiation__DOT__divider__DOT__lpm_remainderpositive;
        SData/*15:0*/ test__DOT__sdram_module__DOT__mem_array[4194304];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__registers[10];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__shadow_registers[10];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_vector_table[8];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[10];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[10];
        CData/*7:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[5];
        CData/*7:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer[16080];
        WData/*127:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage[256][4];
        CData/*7:0*/ test__DOT__top_instantiation__DOT__program_rom__DOT__rom_memory[4219];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[17];
        IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[17];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound2;
    CData/*7:0*/ test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound1;
    CData/*0:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr;
    CData/*7:0*/ __Vdlyvval__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller_init_done;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
    CData/*2:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
    CData/*1:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
    CData/*1:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
    CData/*0:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
    CData/*0:0*/ __VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__vga_clk_supplied;
    CData/*0:0*/ __Vclklast__TOP__dram_clk_supplied;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vclklast__TOP__test__DOT__PS2_CLK;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
    CData/*0:0*/ __Vchglast__TOP__test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished;
    SData/*15:0*/ test__DOT__sdram_module__DOT__zs_dq__out__en0;
    SData/*15:0*/ test__DOT__sdram_module__DOT__read_temp__out1;
    SData/*15:0*/ test__DOT__sdram_module__DOT__read_temp__out2;
    SData/*13:0*/ __Vdlyvdim0__test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
    SData/*12:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
    SData/*8:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
    SData/*8:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
    SData/*15:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound1;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound2;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound3;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound4;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound5;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound6;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound7;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound8;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound9;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound10;
    IData/*31:0*/ test__DOT__top_instantiation__DOT____Vlvbound11;
    IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound2;
    IData/*31:0*/ test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound2;
    IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound5;
    IData/*31:0*/ test__DOT__top_instantiation__DOT__divider__DOT____Vlvbound6;
    IData/*21:0*/ __Vdly__test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
    QData/*40:0*/ test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
    CData/*2:0*/ __Vtablechg1[512];
    CData/*0:0*/ __Vm_traceActivity[8];
    static CData/*1:0*/ __Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries[512];
    static CData/*0:0*/ __Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address[512];
    static CData/*0:0*/ __Vtable1_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address[512];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtest__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtest);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtest(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtest();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vtest__Syms* __restrict vlSymsp);
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
    void __Vconfigure(Vtest__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtest__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtest__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtest__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__12(Vtest__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__13(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vtest__Syms* __restrict vlSymsp);
    static void _settle__TOP__9(Vtest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
