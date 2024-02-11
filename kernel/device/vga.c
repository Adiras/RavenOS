#include <device/vga.h>
#include <ports.h>

void clear_screen() 
{
  for (int i = 0; i < VGA_TEXT_ROWS; i++)
    for (int j = 0; j < VGA_TEXT_COLUMNS; j++)
      print_char(' ', i, j, COLOR_BLACK, COLOR_BLACK, 0);
}

void console_write(char *str)
{
    int offset = get_cursor();
    int row = get_row_from_offset(offset);
    int col = get_col_from_offset(offset);

    int i = 0;
    while (str[i] != '\0') {
      if (str[i] == '\n') {
        col = 0;
        row++;
        offset = get_offset(col, row);
        i++;
        continue;
      }

      print_char(str[i], col, row, COLOR_BLACK, COLOR_GRAY, 0);
      i++;
      col++;
      offset += 2;
    }

    set_cursor(offset);
}

void print_char(char code_point, short col, short row, char bg_color, char fg_color, char blink)
{
    volatile unsigned char *video_memory = (volatile unsigned char *)0xB8000;

    unsigned char attribute = 0 << 7 | bg_color << 4 | fg_color;
    int offset = (row * VGA_TEXT_COLUMNS + col) * 2;
    video_memory[offset] = code_point;
    video_memory[offset + 1] = attribute;
}

void set_cursor(int offset)
{
    offset /= 2;
    port_byte_out(VGA_CTRL_REG, 14);
    port_byte_out(VGA_DATA_REG, (unsigned char)(offset >> 8));
    port_byte_out(VGA_CTRL_REG, 15);
    port_byte_out(VGA_DATA_REG, (unsigned char)(offset & 0xFF));
}

int get_cursor()
{
    port_byte_out(VGA_CTRL_REG, 14);
    int offset = port_byte_in(VGA_DATA_REG) << 8;
    port_byte_out(VGA_CTRL_REG, 15);
    offset += port_byte_in(VGA_DATA_REG);
    return offset * 2;
}

int get_offset(int col, int row)
{
    return 2 * (row * VGA_TEXT_COLUMNS + col);
}

int get_row_from_offset(int offset)
{
    return offset / (2 * VGA_TEXT_COLUMNS);
}

int get_col_from_offset(int offset)
{
    return offset / 2 % VGA_TEXT_COLUMNS;
}