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


// %Zr
int zekendorfFlag(unsigned int num, char *result) {
    if (num == 0) {
        strcpy(result, "01");
        return 2;
    }

    unsigned int fibi[47];
    fibi[0] = 1;
    fibi[1] = 2;
    int k = 1;

    for (int i = 2; i < 47; i++) {
        unsigned int next = fibi[i - 1] + fibi[i - 2];
        if (next < fibi[i - 1] || next > num) {
            k = i - 1;
            break;
        }
        fibi[i] = next;
        k = i;
    }

    char otv[48];
    int len = 0;
    unsigned int temp = num;

    for (int i = k; i >= 0; i--) {
        if (temp >= fibi[i]) {
            otv[len++] = '1';
            temp -= fibi[i];
        } else {
            otv[len++] = '0';
        }
    }

    int index = 0;
    for (int i =0; i < len; i++) {
        result[index++] = otv[len - i - 1];
    }

    result[index++] = '1';
    result[index] = '\0';

    return index;
}

int argsZekendorfFlag(va_list args, char *result) {
    unsigned int arg = va_arg(args, unsigned int);

    return zekendorfFlag(arg, result);
}

// %Cv / %CV
int fromDecimalFlag(int base, int num, char *result, bool capitalize) {
    if (base < 2 || base > 36) { base = 10; }
    if (base == 10) { return sprintf(result, "%d", num); }
    
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return 1;
    }
    
    char buff[34];
    int i = 0;
    bool negative = false;

    if (num < 0) {
        negative = true;
        num = -num;
    }

    char letterType = capitalize ? 'A' : 'a';

    while (num > 0) {
        int digit = num % base;

        if (digit < 10) {
            buff[i] = digit + '0';
        } else {
            buff[i] = (digit - 10) + letterType;
        }
        num /= base;
        i++;
    }
    
    if (negative) { buff[i++] = '-'; }

    char *ptr = result;

    for (int k = i - 1; k >= 0; k--) {
        *ptr = buff[k];
        ptr++;
    }

    *ptr = '\0';

    return ptr - result;
}

// %Cv
int fromDecimalLower(va_list args, char *result) {
    int num = va_arg(args, int);
    int base = va_arg(args, int);

    return fromDecimalFlag(base, num, result, false);
}

// %CV
int fromDecimalUpper(va_list args, char *result) {
    int num = va_arg(args, int);
    int base = va_arg(args, int);

    return fromDecimalFlag(base, num, result, true);
}
