#[macro_use]
extern crate bitfield;

#[macro_use]
extern crate num_derive;

pub mod cpu {
    pub type RawConstantOperand = u32;
    pub type SignedRawConstantOperand = i32;
    pub const CONSTANT_SIZE: usize = std::mem::size_of::<RawConstantOperand>();
    pub const INSTRUCTION_SIZE: usize = 7;
    pub const NUM_REGISTERS: usize = 12;
    pub const TOTAL_RAM_SIZE_BYTES: usize = 8_000_000;
    pub const GPU_TEXT_DISPLAY_ROWS: usize = 67; // rows of text
    pub const GPU_TEXT_DISPLAY_COLUMNS: usize = 240; // columns of text
    pub const GPU_TEXT_BUFFER_LENGTH: usize = GPU_TEXT_DISPLAY_ROWS * GPU_TEXT_DISPLAY_COLUMNS; // characters of text
    pub const NUM_INTERRUPTS: usize = 8; // interrupts

    pub const REGISTER_IP: usize = 0;
    pub const REGISTER_OF: usize = 11;

    pub const INTERRUPT_VALUE_PORT: usize = 0;
    pub const SD_CARD_SPI_PORT: usize = 1;
    pub const SD_CARD_CLOCK_SELECT_PORT: usize = 2;
    pub const GPU_TEXT_BUFFER_PORT: usize = 3;

    #[derive(Debug, Clone, Copy, FromPrimitive)]
    pub enum Operation {
        NOP = 0,
        LOAD = 1,
        STORE = 2,
        ADD = 3,
        MULT = 4,
        DIV = 5,
        OUT = 6,
        IN = 7,
        MOV = 8,
        CMP = 9,
        JMP = 10,
        RST = 11,
        HALT = 12,
        ISR = 13,
        INT = 14,
        ENDINT = 15,
        OR = 16,
        AND = 17,
        XOR = 18,
        NOT = 19,
        SHIFT = 20
    }

    #[derive(Debug, Clone, Copy, FromPrimitive)]
    pub enum Register {
        IP = 0,
        A = 1,
        B = 2,
        C = 3,
        D = 4,
        E = 5,
        F = 6,
        G = 7,
        IE = 8,
        IR = 9,
        ZD = 10,
        OF = 11
    }

    #[derive(Debug, Clone, Copy, FromPrimitive, PartialEq)]
    pub enum Variant {
    }

    impl Variant {
        pub const NONE: u8 = 0;
        pub const LOAD_RR: u8 = 0;
        pub const LOAD_CR: u8 = 1;
        pub const STORE_RR: u8 = 0;
        pub const STORE_CR: u8 = 1;
        pub const STORE_RC: u8 = 2;
        pub const ADD_RRR: u8 = 0;
        pub const ADD_RCR: u8 = 1;
        pub const MULT_RRR: u8 = 0;
        pub const MULT_RCR: u8 = 1;
        pub const DIV_RRR: u8 = 0;
        pub const DIV_RCR: u8 = 1;
        pub const DIV_CRR: u8 = 2;
        pub const MOD_RRR: u8 = 3;
        pub const MOD_RCR: u8 = 4;
        pub const MOD_CRR: u8 = 5;
        pub const OUT_RR: u8 = 0;
        pub const OUT_CR: u8 = 1;
        pub const OUT_RC: u8 = 2;
        pub const IN_RR: u8 = 0;
        pub const IN_CR: u8 = 1;
        pub const MOV_RR: u8 = 0;
        pub const MOV_CR: u8 = 1;
        pub const CMP_RRR: u8 = 0;
        pub const CMP_RCR: u8 = 1;
        pub const CMP_CRR: u8 = 2;
        pub const JMP_U: u8 = 0;
        pub const JMP_E: u8 = 1;
        pub const JMP_NE: u8 = 2;
        pub const JMP_L: u8 = 3;
        pub const JMP_G: u8 = 4;
        pub const JMP_LE: u8 = 5;
        pub const JMP_GE: u8 = 6;
        pub const INT_R: u8 = 0;
        pub const INT_C: u8 = 1;
        pub const OR_RRR: u8 = 0;
        pub const OR_RCR: u8 = 1;
        pub const AND_RRR: u8 = 0;
        pub const AND_RCR: u8 = 1;
        pub const XOR_RRR: u8 = 0;
        pub const XOR_RCR: u8 = 1;
        pub const SHIFT_L_RRR: u8 = 0;
        pub const SHIFT_L_RCR: u8 = 1;
        pub const SHIFT_R_RRR: u8 = 2;
        pub const SHIFT_R_RCR: u8 = 3;
        pub const SHIFT_L_CRR: u8 = 4;
        pub const SHIFT_R_CRR: u8 = 5;
    }

    bitfield! {
        pub struct InstructionBitfield([u8]); // Bit order is least-significant-bit-first.
        impl Debug;
        u8;
        pub get_operation, set_operation: 4, 0;
        pub get_variant, set_variant: 7, 5;
        pub get_size, set_size: 9, 8;
        pub get_register_operand_1, set_register_operand_1: 13, 10;
        pub get_register_operand_2, set_register_operand_2: 17, 14;
        pub get_register_operand_3, set_register_operand_3: 21, 18;
        pub RawConstantOperand, get_constant_operand, set_constant_operand: 49, 18;
    }
}
