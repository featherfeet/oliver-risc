library verilog;
use verilog.vl_types.all;
entity top is
    port(
        KEY             : in     vl_logic_vector(3 downto 0);
        CLOCK_50        : in     vl_logic;
        SW              : in     vl_logic_vector(9 downto 0);
        HEX0            : out    vl_logic_vector(6 downto 0);
        HEX1            : out    vl_logic_vector(6 downto 0);
        HEX2            : out    vl_logic_vector(6 downto 0);
        HEX3            : out    vl_logic_vector(6 downto 0);
        DRAM_CLK        : out    vl_logic;
        DRAM_ADDR       : out    vl_logic_vector(11 downto 0);
        DRAM_BA_0       : out    vl_logic;
        DRAM_BA_1       : out    vl_logic;
        DRAM_CAS_N      : out    vl_logic;
        DRAM_CKE        : out    vl_logic;
        DRAM_CS_N       : out    vl_logic;
        DRAM_LDQM       : out    vl_logic;
        DRAM_UDQM       : out    vl_logic;
        DRAM_RAS_N      : out    vl_logic;
        DRAM_WE_N       : out    vl_logic;
        DRAM_DQ         : inout  vl_logic_vector(15 downto 0);
        VGA_R           : out    vl_logic_vector(3 downto 0);
        VGA_G           : out    vl_logic_vector(3 downto 0);
        VGA_B           : out    vl_logic_vector(3 downto 0);
        VGA_HS          : out    vl_logic;
        VGA_VS          : out    vl_logic
    );
end top;
