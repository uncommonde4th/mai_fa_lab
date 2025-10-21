#include <stdio.h>
#include <stdlib.h>
#include "../include/checkFR.h"


int main(int argc, char *argv[]) {
        if (argc != 1) {
                printf("Ошибка: Программа не принимает аргументов\n");
                return 1;
        }
        
        int numOfArgs = 4;
        int base = 2;

        bool *resultArray = (bool *)calloc(numOfArgs, sizeof(bool));
        if (resultArray == NULL) {
                printf("Ошибка: Не удалось выделить память\n");
                return 1;
        }

        ErrorCode res = checkFRVariableArgs(resultArray, base, numOfArgs, 0.5, 0.25, 0.00001, 0.8929310013);

        switch(res) {
                case ERROR_BAD_NUM: 
                        printf("Ошибка: Все аргументы должны быть в диапазоне (0;1)\n");
                        break;
                case ERROR_BAD_BASE:
                        printf("Ошибка: Основание CC должно быть больше единицы\n");
                        break;
                case ERROR_NOT_ENOUGH_ARGS:
                        printf("Ошибка: В функцию должен быть передан хотя бы один элемент для проверки\n");
                        break;
                case SUCCESS:
                        printf("В системе счисления с основанием %d:\n", base);
                        for (int i = 0; i < numOfArgs; i++) {
                                if (resultArray[i]) {
                                        printf("\033[32mЧисло №%d имеет конечное представление\033[0m\n", i + 1);
                                } else {
                                        printf("\033[31mЧисло №%d не имеет конечного представления\033[0m\n", i + 1);
                                }
                        }
                        break;
        }

        return 0;
}
