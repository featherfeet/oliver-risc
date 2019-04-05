// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/main/ip/sopc/components/verification/altera_tristate_conduit_bfm/altera_tristate_conduit_bfm.sv.terp#7 $
// $Revision: #7 $
// $Date: 2010/08/05 $
// $Author: klong $
//-----------------------------------------------------------------------------
// =head1 NAME
// altera_conduit_bfm
// =head1 SYNOPSIS
// Bus Functional Model (BFM) for a Standard Conduit BFM
//-----------------------------------------------------------------------------
// =head1 DESCRIPTION
// This is a Bus Functional Model (BFM) for a Standard Conduit Master.
// This BFM sampled the input/bidirection port value or driving user's value to 
// output ports when user call the API.  
// This BFM's HDL is been generated through terp file in Qsys/SOPC Builder.
// Generation parameters:
// output_name:                                       altera_conduit_bfm
// role:width:direction:                              address:23:output,byte_enable:2:output,read:1:output,write:1:output,write_data:16:output,acknowledge:1:input,read_data:16:input
// false
//-----------------------------------------------------------------------------
`timescale 1 ns / 1 ns

module altera_conduit_bfm
(
   sig_address,
   sig_byte_enable,
   sig_read,
   sig_write,
   sig_write_data,
   sig_acknowledge,
   sig_read_data
);

   //--------------------------------------------------------------------------
   // =head1 PINS 
   // =head2 User defined interface
   //--------------------------------------------------------------------------
   output [22 : 0] sig_address;
   output [1 : 0] sig_byte_enable;
   output sig_read;
   output sig_write;
   output [15 : 0] sig_write_data;
   input sig_acknowledge;
   input [15 : 0] sig_read_data;

   // synthesis translate_off
   import verbosity_pkg::*;
   
   typedef logic [22 : 0] ROLE_address_t;
   typedef logic [1 : 0] ROLE_byte_enable_t;
   typedef logic ROLE_read_t;
   typedef logic ROLE_write_t;
   typedef logic [15 : 0] ROLE_write_data_t;
   typedef logic ROLE_acknowledge_t;
   typedef logic [15 : 0] ROLE_read_data_t;

   reg [22 : 0] address_temp;
   reg [22 : 0] address_out;
   reg [1 : 0] byte_enable_temp;
   reg [1 : 0] byte_enable_out;
   reg read_temp;
   reg read_out;
   reg write_temp;
   reg write_out;
   reg [15 : 0] write_data_temp;
   reg [15 : 0] write_data_out;
   logic [0 : 0] acknowledge_in;
   logic [0 : 0] acknowledge_local;
   logic [15 : 0] read_data_in;
   logic [15 : 0] read_data_local;

   //--------------------------------------------------------------------------
   // =head1 Public Methods API
   // =pod
   // This section describes the public methods in the application programming
   // interface (API). The application program interface provides methods for 
   // a testbench which instantiates, controls and queries state in this BFM 
   // component. Test programs must only use these public access methods and 
   // events to communicate with this BFM component. The API and module pins
   // are the only interfaces of this component that are guaranteed to be
   // stable. The API will be maintained for the life of the product. 
   // While we cannot prevent a test program from directly accessing internal
   // tasks, functions, or data private to the BFM, there is no guarantee that
   // these will be present in the future. In fact, it is best for the user
   // to assume that the underlying implementation of this component can 
   // and will change.
   // =cut
   //--------------------------------------------------------------------------
   
   event signal_input_acknowledge_change;
   event signal_input_read_data_change;
   
   function automatic string get_version();  // public
      // Return BFM version string. For example, version 9.1 sp1 is "9.1sp1" 
      string ret_version = "13.0";
      return ret_version;
   endfunction

   // -------------------------------------------------------
   // address
   // -------------------------------------------------------

   function automatic void set_address (
      ROLE_address_t new_value
   );
      // Drive the new value to address.
      
      $sformat(message, "%m: method called arg0 %0d", new_value); 
      print(VERBOSITY_DEBUG, message);
      
      address_temp = new_value;
   endfunction

   // -------------------------------------------------------
   // byte_enable
   // -------------------------------------------------------

   function automatic void set_byte_enable (
      ROLE_byte_enable_t new_value
   );
      // Drive the new value to byte_enable.
      
      $sformat(message, "%m: method called arg0 %0d", new_value); 
      print(VERBOSITY_DEBUG, message);
      
      byte_enable_temp = new_value;
   endfunction

   // -------------------------------------------------------
   // read
   // -------------------------------------------------------

   function automatic void set_read (
      ROLE_read_t new_value
   );
      // Drive the new value to read.
      
      $sformat(message, "%m: method called arg0 %0d", new_value); 
      print(VERBOSITY_DEBUG, message);
      
      read_temp = new_value;
   endfunction

   // -------------------------------------------------------
   // write
   // -------------------------------------------------------

   function automatic void set_write (
      ROLE_write_t new_value
   );
      // Drive the new value to write.
      
      $sformat(message, "%m: method called arg0 %0d", new_value); 
      print(VERBOSITY_DEBUG, message);
      
      write_temp = new_value;
   endfunction

   // -------------------------------------------------------
   // write_data
   // -------------------------------------------------------

   function automatic void set_write_data (
      ROLE_write_data_t new_value
   );
      // Drive the new value to write_data.
      
      $sformat(message, "%m: method called arg0 %0d", new_value); 
      print(VERBOSITY_DEBUG, message);
      
      write_data_temp = new_value;
   endfunction

   // -------------------------------------------------------
   // acknowledge
   // -------------------------------------------------------
   function automatic ROLE_acknowledge_t get_acknowledge();
   
      // Gets the acknowledge input value.
      $sformat(message, "%m: called get_acknowledge");
      print(VERBOSITY_DEBUG, message);
      return acknowledge_in;
      
   endfunction

   // -------------------------------------------------------
   // read_data
   // -------------------------------------------------------
   function automatic ROLE_read_data_t get_read_data();
   
      // Gets the read_data input value.
      $sformat(message, "%m: called get_read_data");
      print(VERBOSITY_DEBUG, message);
      return read_data_in;
      
   endfunction

   assign sig_address = address_temp;
   assign sig_byte_enable = byte_enable_temp;
   assign sig_read = read_temp;
   assign sig_write = write_temp;
   assign sig_write_data = write_data_temp;
   assign acknowledge_in = sig_acknowledge;
   assign read_data_in = sig_read_data;


   always @(acknowledge_in) begin
      if (acknowledge_local != acknowledge_in)
         -> signal_input_acknowledge_change;
      acknowledge_local = acknowledge_in;
   end
   
   always @(read_data_in) begin
      if (read_data_local != read_data_in)
         -> signal_input_read_data_change;
      read_data_local = read_data_in;
   end
   


// synthesis translate_on

endmodule


