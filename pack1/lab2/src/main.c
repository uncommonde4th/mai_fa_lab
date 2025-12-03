#include <stdlib.h>
#include "../include/prime.h"

int main(int argc, char *argv[]){
        if (argc != 1) {
                printf("Программа не принимает аргументов\n");
                return 1;
        }

        long long T;
        printf("Введите Т - количество запросов:\n");
        if (scanf("%lld", &T) != 1 || T <= 0 || T > INT_MAX){
                printf("Введите одно натуральное число T\n");
                return 1;
        }
        if (check_input()) {
                printf("Ошибка! Неверный ввод, были введены лишние данные\n");
                return 1;
        }
        
        int *nums = (int*)malloc((int)T * sizeof(int));
        if (nums == NULL) {
                printf("Не удалось выделить память под результат\n");
                return 1;
        }
        
        printf("Введите порядковые номера:\n");
        for (int i = 0; i < T; i++){
                if (scanf("%d", &nums[i]) != 1 || nums[i] <= 0){
                        printf("Введите T натуральных чисел n по одному в строке\n");
                        free(nums);
                        return 1;
                }
                if (check_input()) {
                        printf("Ошибка! Неверный ввод, были введены лишние данные\n");
                        return 1;
                }
        }
        
        int max_number;
        if (max(nums, (int)T, &max_number)) {
                free(nums);
                printf("Ошибка max! Неверно введённые данные\n");
                return 1;
        }

        int* prime_numbers = (int*)calloc(max_number, sizeof(int));

        if (generate_prime(max_number, prime_numbers) == 1) {
                free(prime_numbers);
                free(nums);
                printf("Ошибка! Не удалось найти простые числа\n");
                return 1;
        }
 
        printf("\nРезультат:\n");
        for (int i = 0; i < (int)T; i++) {
                printf("%d \n", prime_numbers[nums[i] - 1]);
        }

        free(prime_numbers);
        free(nums);
        
        return 0;
}
