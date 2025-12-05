#include <math.h>
#include <stddef.h>
#include <float.h>
#include "../include/functions.h"

double double_abs(double x){
    return (x < 0) ? -x : x;
}

unsigned int int_abs(int x){
    return (x < 0) ? -x : x;
}

bool is_equal(const double epsilon, const double a, const double b){
    return double_abs(a - b) < epsilon;
}

ErrorCode q_func(const double e, const double a, const double b, const double c, double *root1, double *root2) {
    if (e <= 0.000000000000001) {
        return EPSILON_IS_TOO_SMALL;
    }

    if (root1 == NULL || root2 == NULL) {
        return NULL_POINTER;
    }

    if (is_equal(e, a, 0.0)) {
        if (is_equal(e, b, 0.0)) {
            if (is_equal(e, c, 0.0)) {
                return INF_ROOTS;
            }
            return NO_ROOTS;
        }
        *root1 = -c / b;
        return NOT_A_SQUARE_EQUATION;
    }

    double d = b * b - 4 * a * c;

    if (is_equal(e, d, 0.0)) {
        *root1 = -b / (2 * a);
        *root2 = *root1;
        return SUCCESS;
    } else if (d > 0) {
        *root1 = (-b + sqrt(d)) / (2 * a);
        *root2 = (-b - sqrt(d)) / (2 * a);
        return SUCCESS;
    } else {
        return NEGATIVE_DISCRIMINANT;
    }
}

ErrorCode m_func(const int a, const int b, bool *result) 
{
    if (result == NULL) {
        return NULL_POINTER;
    }

    if (a == 0 || b == 0) {
        return INVALID_ARGUMENTS;
    }

    if (int_abs(a) % int_abs(b) == 0) {
        *result = 0;
    }
    else {
        *result = 1;
    }

    return SUCCESS;
}

ErrorCode t_func(const double e, const double a, const double b, const double c, bool *result) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return INVALID_ARGUMENTS;
    }

    if (e <= 0.000000000000001) {
        return EPSILON_IS_TOO_SMALL;
    }

    if (result == NULL) {
        return NULL_POINTER;
    }
    if ((a > sqrt(DBL_MAX)) || (b > sqrt(DBL_MAX)) || (c > sqrt(DBL_MAX))
    || (a * a > (DBL_MAX - b * b)) || (b * b > (DBL_MAX - c * c)) || (c * c > (DBL_MAX - a * a))) {
        return OVERFLOW;
    }
    if (double_abs(a * a + b * b - c * c) < e || double_abs(c * c + b * b - a * a) < e || double_abs(a * a + c * c - b * b) < e) {
        *result = 0;
    } else {
        *result = 1;
    }

    return SUCCESS;
}
     
