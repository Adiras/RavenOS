#include <device/keyboard.h>
#include <device/vga.h>
#include <isr.h>
#include <ports.h>
#include <strconv.h>

const char scan_codes_table[] = {
    '?', '?', '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',  '?',
    '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',  '[', ']', '?',  '?',
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z',
    'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', '?', '?',  '?', ' '
};

static void keyboard_callback(IsrRegisters regs)
{
    int scan_code = port_byte_in(0x60);
    char str[] = { scan_codes_table[scan_code], '\0' };
    console_write(str);
}

void keyboard_init()
{
    console_write("Initializing PS/2 device...\n\0");
    register_interrupt_handler(IRQ1, keyboard_callback);
}