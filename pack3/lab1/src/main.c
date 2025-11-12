#include <stdio.h>
#include "../include/fromDecimal.h"

int checkResult(TypeError result) {
    switch (result) {
        case (SUCCESS):
            return 0;
        case (R_OUT_OF_RANGE):
            printf("Ошибка. Недопустимое основание системы счисления!\n");
            return 1;
        case (NULL_OUTPUT):
            printf("Ошибка. Неверный указатель на массив для записи результата работы функции!\n");
            return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Ошибка. Программа не принимает аргументов!\n");
        return 1;
    }

    char output[sizeof(unsigned int) * 8 + 1];
    
    unsigned int number = 1323241;

    for (int i = 1; i < 6; i++) {
        printf("r = %d: ", i);
        if (checkResult(fromDecimal(number, i, output)) == 0) {
            printf("%s\n", output);
        } else { return 1; }
    }
    
    char *nothing = NULL;
    checkResult(fromDecimal(number, 3, nothing));
    checkResult(fromDecimal(number, 6, output));
    return 0;
}
    
