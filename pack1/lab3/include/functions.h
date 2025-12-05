#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <limits.h>

typedef enum {
    SUCCESS = 0,
    OVERFLOW,
    INVALID_ARGUMENTS,
    NULL_POINTER,
    NO_ROOTS,
    NEGATIVE_DISCRIMINANT,
    INF_ROOTS,
    NOT_A_SQUARE_EQUATION,
    EPSILON_IS_TOO_SMALL
} ErrorCode;

double double_abs(double x);
ErrorCode q_func(const double e, const double a, const double b, const double c, double *root1, double *root2);
ErrorCode m_func(const int a, const int b, bool *result);
ErrorCode t_func(const double e, const double a, const double b, const double c, bool *result);

#endif
