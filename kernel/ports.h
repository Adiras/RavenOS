#ifndef PORTS_H
#define PORTS_H

#include <builtin.h>

/**
 * @brief Read 8 bits of data from the specified I/O port.
 *
 * @param port The I/O port address to read from.
 * @return The 8-bit value read from the port.
 */
uint8 port_byte_in(uint16 port);

/**
 * @brief Send 8 bits of data to the specified I/O port.
 *
 * @param port The I/O port address to write to.
 * @param data The 8-bit value to be written.
 */
void port_byte_out(uint16 port, uint8 data);

/**
 * @brief Read 16 bits of data from the specified I/O port.
 *
 * @param port The I/O port address to read from.
 * @return The 16-bit value read from the port.
 */
uint16 port_word_in(uint16 port);

/**
 * @brief Send 16 bits of data to the specified I/O port.
 *
 * @param port The I/O port address to write to.
 * @param data The 16-bit value to be written.
 */
void port_word_out(uint16 port, uint16 data);

/**
 * @brief Read 32 bits of data from the specified I/O port.
 *
 * @param port The I/O port address to read from.
 * @return The 32-bit value read from the port.
 */
uint32 port_dword_in(uint16 port);

/**
 * @brief Send 32 bits of data to the specified I/O port.
 *
 * @param port The I/O port address to write to.
 * @param data The 32-bit value to be written.
 */
void port_dword_out(uint16 port, uint32 data);

#endif