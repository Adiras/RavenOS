#ifndef BUILTIN_H
#define BUILTIN_H

#define NULL ((char *)0) /* The value of a null pointer constant. */


typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef enum
{
    false,
    true
} bool;


/**
 * @brief Extracts the lowest 16 bits of a 16-bit address.
 *
 * @param address The 16-bit address.
 * @return The lowest 16 bits of the address.
 */
#define low_16(address) (uint16)((address) & 0xFFFF)

/**
 * @brief Extracts the highest 16 bits of a 16-bit address.
 *
 * @param addr The 16-bit address.
 * @return The highest 16 bits of the address.
 */
#define high_16(address) (uint16)(((address) >> 16) & 0xFFFF)

#endif