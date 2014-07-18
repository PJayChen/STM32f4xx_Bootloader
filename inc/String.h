#ifndef __STRING_H
#define __STRING_H

#include <stddef.h>


#define MaxDigit 6
/*
* Main part of itoa and xtoa
* Utilize the concept of long division to implement
*/
void _toa(int in_num, char *out_str, int base, int digit);

void xtoa(int in_num, char *out_str);

void itoa(int in_num, char *out_str);

char * strncat(char * dst, const char * src, int n);

size_t strlen(const char *string);
#endif