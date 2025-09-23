#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/functions.h"

int is_prime(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n % 2 == 0) return 0;
        for (int i = 3; i <= (int)sqrt(n); i += 2){
                if (n % i == 0) return 0;
        }
        return 1;
}

void h_func(int x){
        int t = 0;
        for (int i = 1; i <= 100; i++) {
                if (i % x == 0){
                        printf("%d ", i);
                        t = 1;
                }
        }
        if (t == 0){
                printf("В пределах 100 нет чисел, кратных %d", x);
        }
        printf("\n");
}

void p_func(int x){
        if (x < 2){
                printf("Число не простое и не составное");
        }
        else if (is_prime(x)){
                printf("Число простое");
        }
        else{
                printf("Число составное");
        }
        printf("\n");
}

void s_func(int x){
        char x16[100];
        sprintf(x16, "%X", x);
        for (int i = 0; x16[i] != '\0'; i++){
                printf("%c ", x16[i]);
        }
        printf("\n");
}

void e_func(int x){
        if (x > 10){
                printf("Для этого флага число должно быть не больше 10\n");
        }
        else{
                for (int i = 1; i <= 10; i++){
                        printf("%d:", i);
                        for (int j = 1; j <= x; j++){
                                int res = 1;
                                for (int k = 1; k < j; k++){
                                        res *= i;
                                }
                                printf(" %d", res);
                        }
                        printf("\n");
                }
        }
}

void a_func(int x){
        int sum = (x * (x + 1)) / 2;
        printf("%d\n", sum);
}

void f_func(int x){
        int fact = 1;
        for (int i = 1; i <= x; i++){
                fact *= i;
        }
        printf("%d\n", fact);
}



