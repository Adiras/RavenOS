#include <string.h>

int strlen(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

void strreverse(char *begin, char *end)
{
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}