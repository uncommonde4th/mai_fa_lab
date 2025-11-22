#include <stdio.h>
#include "../include/checkBrackets.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Программа принимает один аргумент - строку для проверки!\n");
        return 1;
    }
    
    const char *str = argv[1];
    int result = check_brackets(str);

    if(result == 1) {
        printf("Строка корректно сбалансирована по скобкам.\n");
    } else if (result == 0) {
        printf("Строка не сбалансирована по скобкам.\n");
    } else if (result == -1) {
        printf("Ошибка выделения памяти.\n");
    } else {
        printf("Ошибка при выполнении.\n");
    }
    
    return 0;
}

