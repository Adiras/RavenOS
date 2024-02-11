#ifndef STRING_H
#define STRING_H

/**
 * Calculates the length of a null-terminated string.
 *
 * @param str Pointer to the input string.
 * @return Length of the string (excluding the null terminator).
 */
int strlen(const char *str);

/**
 * @brief Reverses a string in-place.
 *
 * @param begin Pointer to the first character of the string.
 * @param end Pointer to the last character of the string.
 */
void strreverse(char *begin, char *end);

#endif