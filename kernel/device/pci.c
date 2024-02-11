#include <device/pci.h>
#include <device/vga.h>
#include <strconv.h>
#include <ports.h>

uint16 pci_read_word(uint16 bus, uint16 slot, uint16 func, uint16 offset)
{
    unsigned int address = (bus << 16) | (slot << 11) | (func << 8) | (offset & 0xFC) | (0x80000000);
    port_dword_out(PCI_CMD_REG, address);
    return (port_dword_in(0xCFC) >> ((offset & 2) * 8)) & 0xffff;
}

void pci_init()
{
    console_write("Initializing PCI...\n\0");

    char buff[10];

    console_write("Connected PCI devices:\n\0");
    for (int bus = 0; bus < 255; bus++) {
        uint16 device_id = pci_read_word(0, bus, 0, 0);
        if (device_id == 0xFFFF)
            continue;

        format_int(device_id, buff, 16);
        console_write(buff);
        console_write("\n\0");
    }
}