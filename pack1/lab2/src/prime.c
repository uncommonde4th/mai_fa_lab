#include <stdlib.h>
#include <math.h>
#include "../include/prime.h"

ErrorCode max(const int* numbers, const int size, int* result)
{
    if (numbers == NULL || result == NULL || size < 0) {
        return INVALID_ARGUMENTS;
    }

    int max_number = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max_number) {
            max_number = numbers[i];
        }
    }

    *result = max_number;
    return SUCCESS;
}


ErrorCode generate_prime(const int max_index, int *result) {
    if (max_index <= 0 || result == NULL || max_index > 1000000) {
        return INVALID_ARGUMENTS;
    }

    int border;
    if (max_index < 6) {
        border = 20;
    } else {
        border = (int)(max_index * log(max_index) * 1.2) + 100;
    }

    if (border < max_index) {
        return NOT_ABLE_TO_FIND_PRIME;
    }

    char *mask = (char*)malloc(border + 1);
    if (mask == NULL) {
        return NOT_ABLE_TO_FIND_PRIME;
    }
    
    mask[0] = mask[1] = 0;
    for (int i = 2; i <= border; i++) {
        mask[i] = 1;
    }

    for (int i = 2; i * i <= border; i++) {
        if (mask[i]) {
            for (int j = i * i; j <= border; j += i) {
                mask[j] = 0;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= border; i++) {
        if (mask[i]) {
            result[count] = i;
            count++;
            if (count == max_index) {
                break;
            }
        }
    }
    
    free(mask);     

    if (count < max_index) {
        return NOT_ABLE_TO_FIND_PRIME;
    }
    
    return SUCCESS;
}

ErrorCode check_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != '\0' && c != EOF)
    {
        if (c != ' ') {
            return INVALID_INPUT;
        }
    }
    return SUCCESS;
}
