#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(){
        const int T;
        if (scanf("%d", &T) != 1 || T <= 0){
                printf("Введите одно натуральное число T\n");
                return 1;
        }

        int *N = malloc(T * sizeof(int));
        for (int i = 0; i < T; i++){
                if (scanf("%d", &N[i]) != 1 || N[i] <= 0){
                        printf("Введите T натуральных чисел n по одному в строке\n");
                        free(N);
                        return 1;
                }
        }

        int *res = malloc(T * sizeof(int));
        for (int i = 0; i < T; i++){
                int prime;
                if (find_prime(N[i], &prime) != 0){
                        printf("Ошибка нахождения простого числа\n");
                        free(N);
                        free(res);
                }
                N[i] = prime;
        }

        printf("\n");
        for (int i = 0; i < T; i++){
                printf("%d\n", N[i]);
        }

        free(N);
        free(res);
        
        return 0;
}
