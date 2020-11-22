// Size of the text display.
`define GPU_TEXT_DISPLAY_ROWS 'd67
`define GPU_TEXT_DISPLAY_COLUMNS 'd240
`define GPU_DISPLAY_WIDTH_PIXELS 'd1920
`define GPU_DISPLAY_HEIGHT_PIXELS 'd1080

// The dimensions (in pixels) of each character cell. To work with GNU Unifont, character cells should be 8 pixels wide by 16 pixels tall.
`define GPU_CHARACTER_CELL_WIDTH (`GPU_DISPLAY_WIDTH_PIXELS / `GPU_TEXT_DISPLAY_COLUMNS)
`define GPU_CHARACTER_CELL_HEIGHT (`GPU_DISPLAY_HEIGHT_PIXELS / `GPU_TEXT_DISPLAY_ROWS)

// The length of the GPU text buffer.
`define GPU_TEXT_BUFFER_LENGTH (`GPU_TEXT_DISPLAY_ROWS * `GPU_TEXT_DISPLAY_COLUMNS)
