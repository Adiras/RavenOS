#ifndef IDT_H
#define IDT_H

#include <builtin.h>

/* Segment selectors */
#define KERNEL_CS 0x08

/* Interrupt Descriptor Table (IDT) gate */
typedef struct {
    uint16 low_offset;      /* Lower 16 bits of the interrupt handler function address */
    uint16 selector;        /* Code segment selector */
    uint8 reserved;         /* Reserved, should be set to 0 */
    uint8 flags;            /* Type of gate (interrupt gate, trap gate, or task gate) and additional attributes */
    uint16 high_offset;     /* Higher 16 bits of the interrupt handler function address */
} __attribute__((packed)) IdtGateDescriptor;

/* Interrupt Descriptor Table Register (IDTR) that holds the base address and the limit (size) of the IDT */
typedef struct {
    uint16 limit;           /* The maximum byte offset within the table (length in bytes minus 1) */
    uint32 base;            /* The base address that points to the start of the IDT */
} __attribute__((packed)) IdtRegister;

#define IDT_ENTRIES 256

IdtGateDescriptor idt[IDT_ENTRIES]; /* Interrupt Descriptor Table */
IdtRegister idtr;

/**
 * Registers an interrupt gate handler for the specified interrupt number.
 *
 * @param interrupt_number The interrupt number (e.g., 0x21 for keyboard interrupt).
 * @param handler_function Pointer to the interrupt handler function.
 *
 * @note This function assumes that the IDT (Interrupt Descriptor Table) has been set up.
 */
void set_idt_gate(int n, uint32 handler);

/**
 * @brief Initializes the Interrupt Descriptor Table Register.
 */
void set_idtr();

#endif