#ifndef FROM_DECIMAL_H
#define FROM_DECIMAL_H

typedef enum {
    SUCCESS,
    R_OUT_OF_RANGE,
    NULL_OUTPUT,
} TypeError;

TypeError fromDecimal(const int number, int r, char *output);

#endif
