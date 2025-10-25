#ifndef NEWPRINTF_H
#define NEWPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ROMAN,
    ZEKENDORF,
    FROM_DECIMAL_LOWER,
    FROM_DECIMAL_UPPER,
    TO_DECIMAL_LOWER,
    TO_DECIMAL_UPPER,
    DUMP_INT,
    DUMP_UNSIGNED_INT,
    DUMP_DOUBLE,
    DUMP_FLOAT,
    UNKNOWN
} printFlags;

printFlags whatFlag(const char *flag);

int romanFlag(int num, char *result);
int argsRomanFlag(va_list args, char *result);

int zekendorfFlag(unsigned int num, char *result);
int argsZekendorfFlag(va_list args, char *result);


#endif
