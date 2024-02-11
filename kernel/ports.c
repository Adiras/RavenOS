#include <ports.h>

uint8 port_byte_in(uint16 port)
{
    uint8 data;
    __asm__("in %%dx, %%al" : "=a"(data) : "d"(port));
    return data;
}

void port_byte_out(uint16 port, uint8 data)
{
    __asm__ __volatile__("out %%al, %%dx" : : "a"(data), "d"(port));
}

uint16 port_word_in(uint16 port)
{
    uint16 data;
    __asm__("in %%dx, %%ax" : "=a"(data) : "d"(port));
    return data;
}

void port_word_out(uint16 port, uint16 data)
{
    __asm__ __volatile__("out %%ax, %%dx" : : "a"(data), "d"(port));
}

uint32 port_dword_in(uint16 port)
{
    uint32 data;
    asm volatile("inl %%dx, %%eax" : "=a"(data) : "d"(port));
    return data;
}

void port_dword_out(uint16 port, uint32 data)
{
    asm volatile("outl %%eax, %%dx" : : "d"(port), "a"(data));
}