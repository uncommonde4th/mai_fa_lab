#include <stdbool.h>
#include <stdio.h>
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
        if (num== 0.0) { return true; }

        if (num == 1e-12) { return true; }


        const long long max_denominator = 1000000LL;
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

signed int checkFRVariableArgs(const int base, const int count, ...) {
        if (base < 2) { return -1; }

        va_list args;
        va_start(args, count);

        double num = va_arg(args, double);
        for (int i = 0; i < count; i++) {
                if (num >= 1.0) { return i + 1; }

                printf("%.7f ", num);
                if (checkFinalRepresentation(base, num)) { 
                        printf("имеет конечное представление в СС с основанием %d\n", base);
                }
                else {  
                        printf("не имеет конечного представления в СС с основанием %d\n", base);
                }
                num = va_arg(args, double);
        }
        va_end(args);

        return 0;
}

