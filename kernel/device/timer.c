#include <device/timer.h>
#include <device/vga.h>
#include <isr.h>
#include <ports.h>
#include <isr.h>

static void timer_callback(IsrRegisters *regs)
{
    timer_ticks++;
}

void timer_init()
{
    register_interrupt_handler(IRQ0, timer_callback);

    int hz = 10000;
    int divisor = PIT_FREQUENCY_HZ / hz;
    port_byte_out(0x43, 0b00110110);
    port_byte_out(0x40, divisor & 0xFF);
    port_byte_out(0x40, divisor >> 8);
}