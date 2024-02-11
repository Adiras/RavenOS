#include <device/vga.h>
#include <device/keyboard.h>
#include <device/timer.h>
#include <device/pci.h>
#include <isr.h>
#include <idt.h>
#include <string.h>
#include <ports.h>
#include <memory.h>

/* The kernel actual entry point */
void kernel_init()
{
	console_write("Initializing kernel code...\n\0");

	isr_install();
	irq_install();

	pci_init();
	keyboard_init();
	timer_init();
}