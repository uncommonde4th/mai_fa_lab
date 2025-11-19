#include <string.h>
#include "../include/fromDecimal.h"

int decrement(int number) {
    if (number == 0) { return -1; }
    int mask = 1;
    
    int minus_one = ~0;
    
    while (minus_one != 0) {
        int temp = number & minus_one;
        number = number ^ minus_one;
        minus_one = temp << 1;
    }

    return number;
}

int increment(int number) {
    int mask = 1;

    while (number & mask) {
        number = number & ~mask;
        mask = mask << 1;
    }

    return number | mask;
}

TypeError fromDecimal(const int number, int r, char *output) {
    if (r > 5 || r < 1) { return R_OUT_OF_RANGE; }
    if (output == NULL) { return NULL_OUTPUT; }

    const unsigned int mask = decrement(1 << r);
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    
    if ((number | 0) == 0) {
        output[0] = '0';
        output[1] = '\0';
        return SUCCESS;
    }

    char buff[50];
    int index = 0;
    
    int is_negative = (number & (1 << 31)) != 0;
    
    unsigned int num;
    if (is_negative) {
        num = (unsigned int)(increment(~number));
    } else {
        num = (unsigned int)number;
    }

    while (num != 0) {
        unsigned int digit = num & mask;
        buff[index] = digits[digit];
        index = increment(index);
        num = num >> r;
    }
    
    int output_index = 0;
    if (is_negative) {
        output[output_index] = '-';
        output_index = increment(output_index);
    }
    
    int i = decrement(index);
    while (1) {
        output[output_index] = buff[i];
        output_index = increment(output_index);
        
        if (i == 0) break;
        i = decrement(i);
    }
    output[output_index] = '\0';

    return SUCCESS;
}
