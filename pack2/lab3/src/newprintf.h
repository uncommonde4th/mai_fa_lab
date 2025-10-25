#include "../include/newprintf.h"

// Функция обработки флагов
printFlags whatFlag(const char *flag) {
    const char *ptr = flag;
    
    if (*ptr == '\0') { return UNKNOWN; }
    if (ptr[0] == 'R' && ptr[1] == 'o') { return ROMAN; }
    if (ptr[0] == 'Z' && ptr[1] == 'r') { return ZEKENDORF; }
    if (ptr[0] == 'C') {
        if (ptr[1] == 'v') { return FROM_DECIMAL_LOWER; }
        if (ptr[1] == 'V') { return FROM_DECIMAL_UPPER; }
    }
    if (ptr[0] == 't') { return TO_DECIMAL_LOWER; }
    if (ptr[0] == 'T') { return TO_DECIMAL_UPPER; }
    if (ptr[0] == 'm') {
        if (ptr[1] == 'i') { return DUMP_INT; }
        if (ptr[1] == 'u') { return DUMP_UNSIGNED_INT; }
        if (ptr[1] == 'd') { return DUMP_DOUBLE; }
        if (ptr[1] == 'f') { return DUMP_FLOAT; }
    }

    return UNKNOWN;
}


// %Ro
int romanFlag(int num, char *result) {
    if (num <= 0 || num > 3999) {
        int len = sprintf(result, "[%d]", num);
        if (len < 0) { return 0; }
        else { return len; }
    }

    const char *romanNums[] = { "M", "CM", "D", "CD", "C", "XC", "L", "X", "IX", "V", "IV", "I" };
    const unsigned int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    char *ptr = result;
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            size_t len = strlen(romanNums[i]);
            strncpy(ptr, romanNums[i], len);
            ptr += len;
            num -= values[i];
        }
    }

    *ptr = '\0';

    return ptr - result;
}

int argsRomanFlag(va_list args, char *result) {
    int arg = va_arg(args, int);
    
    return romanFlag(arg, result);
}


