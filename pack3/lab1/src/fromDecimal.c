#include <string.h>
#include "../include/fromDecimal.h"

int decrement(int number) {
    if (number == 0) { return -1; }
/*    int mask = 1;

    while (!(number & mask)) {
        mask = mask << 1;
        //if (mask == 0) { return number; }
    }

    return number ^ mask;
*/
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
        //if (mask == 0) { return 0; }
    }

    return number | mask;
}

TypeError fromDecimal(const unsigned int number, int r, char *output) {
    if (r > 5 || r < 1) { return R_OUT_OF_RANGE; }
    if (output == NULL) { return NULL_OUTPUT; }

    const unsigned int mask = decrement(1 << r);
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    unsigned int num = number;
    
    if (num == 0) {
        output[0] = '0';
        output[1] = '\0';
        
        return SUCCESS;
    }

    char buff[sizeof(unsigned int) * 8 + 1];
    int index = 0;

    while (num != 0) {
        unsigned int digit = num & mask;

        buff[index] = digits[digit];
        index = increment(index);

        num = num >> r;
    }
    
    int output_index = 0;
    for (int i = decrement(index); i >= 0; i = decrement(i)) {
        output[output_index] = buff[i];
        output_index = increment(output_index);
    }
    output[output_index] = '\0';

    return SUCCESS;
}
    

