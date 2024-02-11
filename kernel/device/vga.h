#ifndef VGA_H
#define VGA_H

#define COLOR_BLACK 0x0
#define COLOR_BLUE 0x1
#define COLOR_GREEN 0x2
#define COLOR_CYAN 0x3
#define COLOR_RED 0x4
#define COLOR_PURPLE 0x5
#define COLOR_BROWN 0x6
#define COLOR_GRAY 0x7
#define COLOR_DARK_GRAY 0x8
#define COLOR_LIGHT_BLUE 0x9
#define COLOR_LIGHT_GREEN 0xA
#define COLOR_LIGHT_CYAN 0xB
#define COLOR_LIGHT_RED 0xC
#define COLOR_LIGHT_PURPLE 0xD
#define COLOR_YELLOW 0xE
#define COLOR_WHITE 0xF

#define HORIZONTAL_TOTAL 0x0
#define HORIZONTAL_DISPLAY_ENABLE_END 0x1
#define START_HORIZONTAL_BLANKING 0x2
#define END_HORIZONTAL_BLANKING 0x3
#define START_HORIZONTAL_RETRACE_PULSE 0x4
#define END_HORIZONTAL_RETRACE 0x5
#define VERTICAL_TOTAL 0x6
#define OVERFLOW 0x7
#define PRESET_ROW_SCAN 0x8
#define MAXIMUM_SCAN_LINE 0x9
#define CURSOR_START 0xA
#define CURSOR_END 0xB
#define START_ADDRESS_HIGH 0xC
#define START_ADDRESS_LOW 0xD
#define CURSOR_LOCATION_HIGH 0xE
#define CURSOR_LOCATION_LOW 0xF
#define VERTICAL_RETRACE_START 0x10
#define VERTICAL_RETRACE_END 0x11
#define VERTICAL_DISPLAY_ENABLE_END 0x12
#define OFFSET 0x13
#define UNDERLINE_LOCATION 0x14
#define START_VERTICAL_BLANKING 0x15
#define END_VERTICAL_BLANKING 0x16
#define CRT_MODE_CONTROL 0x17
#define LINE_COMPARE 0x18

#define VGA_CTRL_REG 0x3D4
#define VGA_DATA_REG 0x3D5

#define VGA_TEXT_COLUMNS 80     /* The number of columns in VGA text mode (typically 80). */
#define VGA_TEXT_ROWS 25        /* The number of rows in VGA text mode (typically 25). */

/**
 * @brief Clears the VGA screen.
 */
void clear_screen();

/**
 * @brief Writes a null-terminated string to the VGA text mode.
 *
 * @param str Pointer to the null-terminated string to be displayed.
 */
void console_write(char *str);

/**
 * @brief Prints a character to the VGA display.
 *
 * This function writes a single character to the VGA text mode buffer
 * at the specified row and column, with customizable foreground color,
 * background color, and blink attribute.
 *
 * @param code_point The character to be printed.
 * @param col The column where the character should be displayed (0-79).
 * @param row The row where the character should be displayed (0-24).
 * @param term_color The color attribute for the character.
 */
void print_char(char code_point, short col, short row, char bg_color, char fg_color, char blink);

/**
 * @brief Sets the cursor position in VGA text mode based on buffer offset.
 *
 * This function moves the cursor to the specified buffer offset in the VGA text mode.
 *
 * @param offset The buffer offset where the cursor should be positioned.
 */
void set_cursor(int offset);

/**
 * @brief Retrieves the current cursor position in VGA text mode.
 *
 * This function reads the current cursor position from the VGA hardware.
 * It calculates the buffer offset based on the row and column indices.
 *
 * @return The buffer offset representing the current cursor position.
 */
int get_cursor();

/**
 * @brief Calculates the VGA buffer offset for a given row and column.
 *
 * @param col The column index (0-79).
 * @param row The row index (0-24).
 * @return The VGA buffer offset corresponding to the specified position.
 */
int get_offset(int col, int row);

/**
 * @brief Gets the row index from a VGA buffer offset.
 *
 * Given a buffer offset, this function calculates the corresponding row index.
 *
 * @param offset The buffer offset representing a position in VGA text mode.
 * @return The row index (0-24) corresponding to the offset.
 */
int get_row_from_offset(int offset);

/**
 * @brief Gets the column index from a VGA buffer offset.
 *
 * Given a buffer offset, this function calculates the corresponding column index.
 *
 * @param offset The buffer offset representing a position in VGA text mode.
 * @return The column index (0-79) corresponding to the offset.
 */
int get_col_from_offset(int offset);

#endif