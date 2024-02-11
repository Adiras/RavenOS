#include <idt.h>

void set_idt_gate(int n, uint32 handler)
{
    idt[n].low_offset = low_16(handler);
    idt[n].selector = KERNEL_CS;
    idt[n].reserved = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = high_16(handler);
}

void set_idtr()
{
    idtr.base = (uint32)&idt;
    idtr.limit = IDT_ENTRIES * sizeof(IdtGateDescriptor) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r"(&idtr));
}