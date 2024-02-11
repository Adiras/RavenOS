#ifndef PCI_H
#define PCI_H

#define PCI_CMD_REG 0xCF8
#define PCI_DATA_REG 0xCFC

#define PCI_INVALID_VENDOR_ID 0xFFFF

void pci_init();

#endif