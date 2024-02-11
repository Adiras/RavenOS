#include <strconv.h>
#include <memory.h>
#include <builtin.h>
#include <string.h>

void format_int(int value, char *str, int base)
{
  static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";

  char *temp = str;
  int sign;

  if ((sign = value) < 0)
    value = -value;

  do {
    *temp++ = num[value % base];
  } while (value /= base);

  if (sign < 0)
    *temp++ = '-';

  *temp = '\0';
  strreverse(str, temp - 1);
}