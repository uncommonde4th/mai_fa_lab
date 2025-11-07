#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/functions.h"

typedef enum {
    UNKNOWN,
    ROMAN,
    ZEKENDORF,
    FROM_DECIMAL_UPPER,
    FROM_DECIMAL_LOWER,
    TO_DECIMAL_UPPER,
    TO_DECIMAL_LOWER,
    DUMP_FLOAT,
    DUMP_DOUBLE,
    DUMP_UNSIGNED_INT,
    DUMP_INT
} PrintFlags;

// Функция обработки флагов
PrintFlags whatFlag(const char *flag) {
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
        return sprintf(result, "[%d]", num);
    }

    const char *romanNums[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    const unsigned int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    char *ptr = result;
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            const char *roman = romanNums[i];
            while (*roman) {
                *ptr++ = *roman++;
            }
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

// %to %TO
int toDecimalFlag(const char *num, int base, char *output, bool capitalize) {
    if (base < 2 || base > 36) {
        base = 10;
    }

    long long result = 0;
    int sign = 1;

    const char *ptr = num;
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }

    while (*ptr != '\0') {
        char tmp = *ptr;
        int value;

        if (capitalize) { tmp = toupper(tmp); } 
        else { tmp = tolower(tmp); }
        if (tmp >= '0' && tmp <= '9') { value = tmp - '0'; }
        if (tmp >= 'a' && tmp <= 'z') { value = tmp - 'a' + 10; }
        if (tmp >= 'A' && tmp <= 'Z') { value = tmp - 'A' + 10; }

        if (value < 0 || value >= base) {
            result = 0;
            return sprintf(output, "%d", 0);
        }

        if (result > (LLONG_MAX - value) / base) {
            result = 0;
            return sprintf(output, "%d", 0);
        }
        
        result = result * base + value;
        ptr++;
    }

    return sprintf(output, "%lld", (long long)(result * sign));
}

// %to
int toDecimalLower(va_list args, char *output) {
    char *str = va_arg(args, char*);    
    int base = va_arg(args, int);

    return toDecimalFlag(str, base, output, false);
}

// %TO
int toDecimalUpper(va_list args, char *output) {
    char *str = va_arg(args, char*);
    int base = va_arg(args, int);

    return toDecimalFlag(str, base, output, true);
}

// %mi %mu %md %mf
int dumpFlag(void *num, size_t typeSize, char *output) {
    unsigned char *bytes = (unsigned char*)num;
    char *ptr = output;

    for (size_t i = 0; i < typeSize; i++) {
        for (int j = 7; j >= 0; j--) {
            *ptr++ = (bytes[i] & (1 << j)) ? '1' : '0';
        }
        if (i < typeSize - 1) {
            *ptr++ = ' ';
        }
    }
    *ptr = '\0';
    
    return ptr - output;
}
// %mi
int dumpInt(va_list args, char *output) {
    int num = va_arg(args, int);
    return dumpFlag(&num, sizeof(int), output);
}

// %mu
int dumpUnsignedInt(va_list args, char *output) {
    unsigned int num = va_arg(args, unsigned int);
    return dumpFlag(&num, sizeof(unsigned int), output);
}

// %md
int dumpDouble(va_list args, char *output) {
    double num = va_arg(args, double);
    return dumpFlag(&num, sizeof(double), output);
}

// %mf
int dumpFloat(va_list args, char *output) {
    double tmp = va_arg(args, double);
    float num = (float)tmp;
    return dumpFlag(&num, sizeof(float), output);
}

int standartFlag(const char **format, va_list args, char *output) {
    char flag[128];
    char *currWrite = flag;
    const char *standart = "diuoxXfFeEgGaAcspn%%";

    *currWrite++ = '%';
    
    const char *curr = *format;
    
    while ((currWrite - flag < 127) && *curr != '\0' && strchr(standart, *curr) == NULL) {
        *currWrite++ = *curr;
        curr++;
    }

    if (*curr != '\0') {
        *currWrite++ = *curr;
        curr++;
    }

    *currWrite = '\0';

    *format = curr;

    return vsprintf(output, flag, args);
}

int flagHandler(PrintFlags flag, va_list args, char *output) {
    switch (flag) {
        case ROMAN:
            return argsRomanFlag(args, output);
        case ZEKENDORF:
            return argsZekendorfFlag(args, output);
        case FROM_DECIMAL_UPPER:
            return fromDecimalUpper(args, output);
        case FROM_DECIMAL_LOWER:
            return fromDecimalLower(args, output);
        case TO_DECIMAL_LOWER:
            return toDecimalLower(args, output);
        case TO_DECIMAL_UPPER:
            return toDecimalUpper(args, output);
        case DUMP_INT:
            return dumpInt(args, output);
        case DUMP_FLOAT:
            return dumpFloat(args, output);
        case DUMP_DOUBLE:
            return dumpDouble(args, output);
        case DUMP_UNSIGNED_INT:
            return dumpUnsignedInt(args, output);
        default:
            return -1;
    }
}

int overfprintf(FILE *stream, const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *ptr = format;
    int result = 0;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++;

            if (*ptr == '%') {
                fputc(*ptr, stream);
                result++;
                ptr++;
                continue;
            }

            char buff[2048];

            PrintFlags flag = whatFlag(ptr);
            int tmpResult = 0;

            if (flag == UNKNOWN) {
                tmpResult = standartFlag(&ptr, args, buff);
            } else {
                ptr += 2;
                tmpResult = flagHandler(flag, args, buff);
            }

            if (tmpResult < 0) {
                va_end(args);
                return -1;
            }

            buff[tmpResult] = '\0';
            fprintf(stream, "%s", buff);
            result += tmpResult;
        } else {
            fputc(*ptr, stream);
            result++;
            ptr++;
        }
    }
    va_end(args);

    return result;
}

int oversprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *ptr = format;
    char *writePtr = str;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++;

            if (*ptr == '%') {
                *writePtr++ = *ptr;
                ptr++;
                continue;
            }

            char buff[2048];

            PrintFlags flag = whatFlag(ptr);
            int tmpResult = 0;

            if (flag == UNKNOWN) {
                tmpResult = standartFlag(&ptr, args, buff);
            } else {
                ptr += 2;
                tmpResult = flagHandler(flag, args, buff);
            }

            if (tmpResult < 0) {
                va_end(args);
                *writePtr = '\0';
                return -1;
            }

            strncpy(writePtr, buff, tmpResult);
            writePtr += tmpResult;
        } else {
            *writePtr++ = *ptr;
            ptr++;
        }
    }
    *writePtr = '\0';
    va_end(args);

    return writePtr - str;
}




