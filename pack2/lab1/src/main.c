#include <stdio.h>
#include "../include/checkFR.h"


int main() {
        signed int res = checkFRVariableArgs(4, 4, 0.5, 0.25, 1.00001, 0.8929310013);
        switch(res) {
                case -1: 
                        printf("Ошибка: Основание СС должно быть больше единицы\n");
                        break;
                default:
                        if (res != 0) { printf("Ошибка: Аргумент %d больше или равен единице\n", res); }
                        break;
        }
        return 0;
}
