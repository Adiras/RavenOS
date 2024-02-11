#ifndef STRCONV_H
#define STRCONV_H
  
/**
 * @brief Converts a number to its string representation.
 *
 * This function takes an number value and converts it to a string.
 * The resulting string is stored in the provided buffer.
 *
 * @param value The integer value to convert.
 * @param str The buffer to store the resulting string (must have enough space).
 * @param base The base for the conversion (usually 10 for decimal).
 * 
 * @note The resulting string is null-terminated.
 */
void format_int(int value, char* str, int base);

#endif