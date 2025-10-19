#include <stdio.h>
#include "../include/checkFR.h"


int main() {
        switch (checkFRVariableArgs(4, 4, 0.5, 0.25, 0.00001, 0.8929310013)) {
                case 1: 
                        printf("Ошибка: Основание СС должно быть больше единицы\n");
                        break;
                case 2:
                        printf("Ошибка: Аргумент больше или равен единице\n");
                        break;
        }
        return 0;
}
