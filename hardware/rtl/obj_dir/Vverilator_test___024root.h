// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_test.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TEST___024ROOT_H_
#define VERILATED_VVERILATOR_TEST___024ROOT_H_  // guard

#include "verilated.h"

class Vverilator_test__Syms;
VL_MODULE(Vverilator_test___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset_n,0,0);
        VL_IN8(verilator_only_dram_clk,0,0);
        VL_IN8(verilator_only_vga_pixel_clock,0,0);
        CData/*3:0*/ verilator_test__DOT__VGA_R;
        CData/*3:0*/ verilator_test__DOT__VGA_G;
        CData/*3:0*/ verilator_test__DOT__VGA_B;
        CData/*0:0*/ verilator_test__DOT__spi_sclk;
        CData/*0:0*/ verilator_test__DOT__spi_copi;
        CData/*2:0*/ verilator_test__DOT__sdram_module__DOT__latency;
        CData/*1:0*/ verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0;
        CData/*1:0*/ verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1;
        CData/*1:0*/ verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2;
        CData/*2:0*/ verilator_test__DOT__sdram_module__DOT__rd_valid_pipe;
        CData/*1:0*/ verilator_test__DOT__sdram_module__DOT__read_mask;
        CData/*0:0*/ verilator_test__DOT__sdram_module__DOT__read_valid;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__SD_DAT;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__operation;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_empty;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_full;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__gpu_write_enable;
        CData/*6:0*/ verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write;
        CData/*6:0*/ verilator_test__DOT__top_instantiation__DOT__gpu_character_read;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__gpu_access_state;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__program_rom_byte;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__program_rom_done;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__program_rom_read_state;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__ram_write_state;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__ram_write_complete;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__ram_read_state;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__ram_read_complete;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__operand_byte_index;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__state;
        CData/*4:0*/ verilator_test__DOT__top_instantiation__DOT__division_delay_counter;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full;
    };
    struct {
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound_h641c722f__0;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column;
        CData/*6:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value;
        CData/*6:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound_hc18ac365__0;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match;
        CData/*7:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending;
        CData/*2:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr;
        CData/*1:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock;
        CData/*0:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling;
        CData/*3:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send;
        CData/*6:0*/ __Vdlyvval__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
        CData/*0:0*/ __Vdlyvset__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
        CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request;
        CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done;
        CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state;
        CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count;
        CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next;
        CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs;
        CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop;
        CData/*2:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count;
    };
    struct {
        CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw;
        CData/*1:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm;
        CData/*1:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries;
        CData/*0:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__verilator_only_vga_pixel_clock;
        CData/*0:0*/ __Vclklast__TOP__reset_n;
        CData/*0:0*/ __Vclklast__TOP__verilator_only_dram_clk;
        SData/*15:0*/ verilator_test__DOT__DRAM_DQ;
        SData/*13:0*/ verilator_test__DOT__sdram_module__DOT__addr_crb;
        SData/*15:0*/ verilator_test__DOT__sdram_module__DOT__read_data;
        SData/*15:0*/ verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0;
        SData/*15:0*/ verilator_test__DOT__sdram_module__DOT__read_temp__en1;
        SData/*13:0*/ verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access;
        SData/*15:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i;
        SData/*15:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o;
        SData/*15:0*/ verilator_test__DOT__top_instantiation__DOT__ram_read_data;
        SData/*10:0*/ verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register;
        SData/*11:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x;
        SData/*13:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell;
        SData/*12:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count;
        SData/*11:0*/ verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count;
        SData/*15:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
        SData/*11:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr;
        SData/*11:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr;
        SData/*15:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data;
        SData/*8:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
        SData/*8:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
        SData/*12:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
        SData/*9:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter;
        SData/*13:0*/ verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse;
        SData/*13:0*/ __Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0;
        SData/*12:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter;
        SData/*8:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state;
        SData/*8:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next;
        SData/*15:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data;
        IData/*31:0*/ verilator_test__DOT__i;
        IData/*23:0*/ verilator_test__DOT__sdram_module__DOT__CODE;
        IData/*21:0*/ verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0;
        IData/*21:0*/ verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1;
        IData/*21:0*/ verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2;
        IData/*21:0*/ verilator_test__DOT__sdram_module__DOT__test_addr;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__operand1;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__operand2;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__code_section_start_address;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__temp_address;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__program_rom_address;
        IData/*21:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider_numerator;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider_denominator;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__0;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__1;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__2;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__0;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__1;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__3;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__4;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__5;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__6;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__2;
    };
    struct {
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound_ha352e82a__0;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound_ha352e82a__0;
        IData/*21:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain;
        IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr;
        IData/*21:0*/ __Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr;
        QData/*40:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data;
        QData/*40:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data;
        QData/*40:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0;
        QData/*40:0*/ verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1;
        VlUnpacked<SData/*15:0*/, 4194304> verilator_test__DOT__sdram_module__DOT__mem_array;
        VlUnpacked<IData/*31:0*/, 10> verilator_test__DOT__top_instantiation__DOT__registers;
        VlUnpacked<IData/*31:0*/, 10> verilator_test__DOT__top_instantiation__DOT__shadow_registers;
        VlUnpacked<IData/*31:0*/, 8> verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table;
        VlUnpacked<IData/*31:0*/, 10> verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items;
        VlUnpacked<IData/*31:0*/, 10> verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items;
        VlUnpacked<CData/*7:0*/, 5> verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items;
        VlUnpacked<CData/*6:0*/, 16080> verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer;
        VlUnpacked<VlWide<4>/*127:0*/, 128> verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage;
        VlUnpacked<CData/*7:0*/, 3544> verilator_test__DOT__top_instantiation__DOT__program_rom__DOT__rom_memory;
        VlUnpacked<IData/*31:0*/, 17> verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe;
        VlUnpacked<IData/*31:0*/, 17> verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vverilator_test__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vverilator_test___024root(const char* name);
    ~Vverilator_test___024root();
    VL_UNCOPYABLE(Vverilator_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vverilator_test__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
