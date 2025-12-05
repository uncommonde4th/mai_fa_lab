#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

typedef enum {
    SUCCESS = 0,
    OVERFLOW,
    OUT_OF_RANGE,
    NOT_ALLOWED_SYMBOL,
    NOT_PRIME_OR_COMPOSITE,
    NULL_POINTER,
    NO_DIGITS_AFTER_MINUS,
    ZERO_DIVISION,
    NUMBERS_NOT_FOUND
} ErrorCode;


ErrorCode h_func(const int x);
ErrorCode p_func(const int x);
ErrorCode s_func(const int x);
ErrorCode e_func(const int x);
ErrorCode a_func(const int x, long *result);
ErrorCode f_func(const int x, long long *result);

#endif
