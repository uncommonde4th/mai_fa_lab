#include <limits.h>
#include <math.h>
#include <ctype.h>
#include "../include/functions.h"

unsigned int intAbs(int x) {
        return (x < 0) ? -x : x;
}

long power(const int base, const int exponent) {
    long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int is_prime(const int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n % 2 == 0) return 0;
        for (int i = 3; i <= (int)sqrt(n); i += 2){
                if (n % i == 0) return 0;
        }
        return 1;
}

ErrorCode h_func(const int x){
        if (x == 0) { return ZERO_DIVISION; }

        int t = 0;
        for (int i = 1; i <= 100; i++) {
                if (i % x == 0){
                        printf("%d ", i);
                        t = 1;
                }
        }
        if (t == 0){
                return NUMBERS_NOT_FOUND;
        }
        printf("\n");

        return SUCCESS;
}

ErrorCode p_func(const int x){
        if (x < 2) { return NOT_PRIME_OR_COMPOSITE; }

        else if (is_prime(x)){
                printf("Число простое");
        }
        else{
                printf("Число составное");
        }
        printf("\n");

        return SUCCESS;
}

ErrorCode s_func(const int x) { 
    short unsigned int digit;
    char buf[32];
    unsigned int number = intAbs(x);
    short unsigned int count = 0;

    while (number) {
        digit = number % 16;
        buf[count] = (digit < 10) ? '0' + digit : 'A' + digit - 10;
        number /= 16;
        count++;
    }

    printf("Результат: ");

    if (x == 0) {
        printf("0 \n");
        return SUCCESS;
    }

    if (x < 0) {
        printf("- ");
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%c ", buf[i]);
    }

    printf("\n");
    return SUCCESS;
}

ErrorCode e_func(const int x){
        if (x > 10 || x < 1) { return OUT_OF_RANGE; }
        
        else{
                printf("Таблица степеней от 1 до %d для чисел 1-10\n", x);
                for (int i = 1; i <= 10; i++){
                        printf("%d: \n", i);
                        for (int j = 1; j <= x; j++){
                                long res = power(i, j);
                                printf("%d ^ %d = %ld \n", i, j, res);
                        }
                        printf("\n");
                }
        }
        
        return SUCCESS;
}

ErrorCode a_func(const int x, long *result) { 
    if (result == NULL) {
        return NULL_POINTER;
    }

    if (x <= 0) {
        return OUT_OF_RANGE;
    }

    long int sum = 0;

    for (int i = 1; i <= x; i++) {
        if (LONG_MAX - i < sum || sum < 0) {
            return OVERFLOW;
        }
        sum += i;
    }

    *result = sum;

    return SUCCESS;
}

ErrorCode f_func(const int x, long long *result) { 
    if (result == NULL) {
        return NULL_POINTER;
    }

    if (x < 0) {
        return OUT_OF_RANGE;
    }

    long long tmp = 1;

    for (int i = 1; i <= x; i++) {
        if (tmp > LLONG_MAX / i || tmp < 0) {
            return OVERFLOW;
        }
        tmp *= i;
    }

    *result = tmp;
    
    return SUCCESS;
}
