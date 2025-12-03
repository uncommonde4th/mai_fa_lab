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
    if (max_index <= 0 || result == NULL) {
        return INVALID_ARGUMENTS;
    }
    
    result[0] = 2;
    
    if (max_index == 1) {
        return SUCCESS;
    }
    
    int count = 1;
    int current = 3;
    
    while (count < max_index) {
        int is_prime = 1;
        
        for (int i = 0; i < count; i++) {
            if (result[i] * result[i] > current) {
                break;
            }
            
            if (current % result[i] == 0) {
                is_prime = 0;
                break;
            }
        }
        
        if (is_prime) {
            result[count] = current;
            count++;
        }
        
        if (current > INT_MAX - 2) {
            return NOT_ABLE_TO_FIND_PRIME;
        }
        current += 2;
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
