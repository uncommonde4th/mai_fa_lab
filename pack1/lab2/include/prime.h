#ifndef PRIME_H
#define PRIME_H

#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef enum {
    SUCCESS = 0,
    INVALID_ARGUMENTS,
    NOT_ABLE_TO_FIND_PRIME,
    INVALID_INPUT
} ErrorCode;

ErrorCode max(const int *nums, const int size, int *result);
ErrorCode generate_prime(const int max_index, int *result);
ErrorCode check_input();

#endif
