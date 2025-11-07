#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdarg.h>
#include <stdio.h>

int overfprintf(FILE *stream, const char *format, ...);
int oversprintf(char *str, const char *format, ...);

#endif
