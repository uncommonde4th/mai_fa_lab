#ifndef CHECKFR_H
#define CHECKFR_H

#include <stdarg.h>
#include <stdbool.h>

typedef enum {
    SUCCESS = 0,
    ERROR_BAD_BASE,
    ERROR_NOT_ENOUGH_ARGS,
    ERROR_BAD_NUM
} ErrorCode;

ErrorCode checkFRVariableArgs(bool *result, const int base, const int count, ...);

#endif
