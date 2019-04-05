/******************************************************************************
 * License Agreement                                                          *
 *                                                                            *
 * Copyright (c) 1991-2013 Altera Corporation, San Jose, California, USA.     *
 * All rights reserved.                                                       *
 *                                                                            *
 * Any megafunction design, and related net list (encrypted or decrypted),    *
 *  support information, device programming or simulation file, and any other *
 *  associated documentation or information provided by Altera or a partner   *
 *  under Altera's Megafunction Partnership Program may be used only to       *
 *  program PLD devices (but not masked PLD devices) from Altera.  Any other  *
 *  use of such megafunction design, net list, support information, device    *
 *  programming or simulation file, or any other related documentation or     *
 *  information is prohibited for any other purpose, including, but not       *
 *  limited to modification, reverse engineering, de-compiling, or use with   *
 *  any other silicon devices, unless such use is explicitly licensed under   *
 *  a separate agreement with Altera or a megafunction partner.  Title to     *
 *  the intellectual property, including patents, copyrights, trademarks,     *
 *  trade secrets, or maskworks, embodied in any such megafunction design,    *
 *  net list, support information, device programming or simulation file, or  *
 *  any other related documentation or information provided by Altera or a    *
 *  megafunction partner, remains with Altera, the megafunction partner, or   *
 *  their respective licensors.  No other licenses, including any licenses    *
 *  needed under any third party's intellectual property, are provided herein.*
 *  Copying or modifying any file, or portion thereof, to which this notice   *
 *  is attached violates this copyright.                                      *
 *                                                                            *
 * THIS FILE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    *
 * FROM, OUT OF OR IN CONNECTION WITH THIS FILE OR THE USE OR OTHER DEALINGS  *
 * IN THIS FILE.                                                              *
 *                                                                            *
 * This agreement shall be governed in all respects by the laws of the State  *
 *  of California and by the laws of the United States of America.            *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *                                                                            *
 * This module connects the an External Bus to Avalon Switch Fabric           *
 *  It acts as both a master for the avalon swtich fabric                     *
 *  and a slave to the master peripheral                                      *
 *                                                                            *
 ******************************************************************************/

module sdram_system_bridge_0 (
	// Inputs
	clk,
	reset,

	// Inputs from Avalon Switch Fabric
	avalon_readdata,
	avalon_waitrequest,

	// Inputs from the master peripheral
	address,
	byte_enable,
	read,
	write,
	write_data,

	// Bidirectionals

	// Outputs
	// Output to Avalon Switch Fabric
	avalon_address,
	avalon_byteenable,
	avalon_read,
	avalon_write,
	avalon_writedata,

	// Outputs to master peripheral
	acknowledge,
	read_data
);


/*****************************************************************************
 *                           Parameter Declarations                          *
 *****************************************************************************/

parameter	AW	= 22;	// Address width
parameter	DW	= 15;	// Data width

parameter	BW	= 1;	// Byte enable width

/*****************************************************************************
 *                             Port Declarations                             *
 *****************************************************************************/
// Inputs
input						clk;
input						reset;

input						avalon_waitrequest;
input			[DW: 0]	avalon_readdata;

input			[AW: 0]	address;
input			[BW: 0]	byte_enable;
input						write;
input						read;
input			[DW: 0]	write_data;

// Bidirectionals

// Outputs
output		[AW: 0]	avalon_address;
output		[BW: 0]	avalon_byteenable;
output					avalon_read;
output					avalon_write;
output		[DW: 0]	avalon_writedata;

output					acknowledge;
output		[DW: 0]	read_data;

/*****************************************************************************
 *                           Constant Declarations                           *
 *****************************************************************************/

/*****************************************************************************
 *                 Internal Wires and Registers Declarations                 *
 *****************************************************************************/

// Internal Wires

// Internal Registers

// State Machine Registers

/*****************************************************************************
 *                         Finite State Machine(s)                           *
 *****************************************************************************/


/*****************************************************************************
 *                             Sequential Logic                              *
 *****************************************************************************/

/*****************************************************************************
 *                            Combinational Logic                            *
 *****************************************************************************/
assign read_data 				= avalon_readdata;
assign avalon_address 		= address;
assign avalon_byteenable	= byte_enable;
assign avalon_write 			= write;
assign avalon_read 			= read;
assign avalon_writedata 	= write_data;
assign acknowledge 			= ~avalon_waitrequest & (avalon_read | avalon_write);

/*****************************************************************************
 *                              Internal Modules                             *
 *****************************************************************************/

endmodule

