#include <stdio.h>
#include "../include/checkBrackets.h"

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Программа не принимает аргументов!\n");
        return 1;
    }

    const char *str = "(){{}<>}";
    int result = check_brackets(str);

    if(result == 1) {
        printf("Строка корректно сбалансирована по скобкам.\n");
    } else if (result == 0) {
        printf("Строка не сбалансирована по скобкам.\n");
    } else if (result == -2) {
        printf("Ошибка. Переполнение стека.\n");
    } else {
        printf("Ошибка при выполнении.\n");
    }
    
    return 0;
}

