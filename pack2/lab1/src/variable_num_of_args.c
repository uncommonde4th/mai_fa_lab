#include "../include/checkFR.h"


int gcd(int a, int b) {
        while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
        }
        return a;
}

bool checkFinalRepresentation(const int base, const double num) {
        if (num == 0.0) { return true; }

        if (num <= 1e-12) { return true; }


        const long long max_denominator = 1000000;
        long long numerator = (long long)(num * max_denominator + 0.5);
        long long denominator = max_denominator;

        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;

        int temp = denominator;
        int base_temp = base;

        for (int d = 2; d <= base_temp; d++) {
                while (base_temp % d == 0) {
                        while (temp % d == 0) {
                                temp /= d;
                        }
                        base_temp /= d;
                }
        }
        return temp == 1;
}

ErrorCode checkFRVariableArgs(bool *result, const int base, const int count, ...) {
        if (base < 2) { return ERROR_BAD_BASE; }
        if (count < 1) { return ERROR_NOT_ENOUGH_ARGS; }

        va_list args;
        va_start(args, count);

        double num = va_arg(args, double);
        for (int i = 0; i < count; i++) {
                if (num >= 1.0 || num <= 0.0) { return ERROR_BAD_NUM; }
                if (checkFinalRepresentation(base, num)) { result[i] = true; }
                else { result[i] = false; }
                num = va_arg(args, double);
        }
        va_end(args);

        return SUCCESS;
}

