#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/functions.h"

int main(int argc, char *argv[]){
	if (argc != 3){
            printf("Формат: %s <число> <флаг>\n", argv[0]);
            return 1;
    }

    long x_long = strtol(argv[1], NULL, 10);
    if (x_long > INT_MAX || x_long < INT_MIN){
            printf("Ошибка! Переполнение.\n");
            return 1;
    }
    const int x = (int)x_long;

    const char *flag = argv[2];
	
	if (flag[0] != '-' && flag[0] != '/'){
		printf("Флаг должен начинаться с '-' или '/'\n");
		return 1;
	}
	else{
		switch(flag[1]){
			case 'h':
				switch(h_func(x)) {
					case ZERO_DIVISION:
						printf("Невозможно найти делители нуля!\n");
						return 1;
					case NUMBERS_NOT_FOUND:
						 printf("В пределах 100 нет чисел, кратных %d\n", x);
						 return 1;
					default:
						 break;
				}
				break;

			case 'p':
				switch(p_func(x)) {
					case NOT_PRIME_OR_COMPOSITE:
						printf("%d не является простым или составным числом\n", x);
						return 1;
					default:
						break;
				}
				break;

			case 's':
				s_func(x);
				break;
			case 'e':
				switch(e_func(x)) {
					case OUT_OF_RANGE:
						printf("Ошибка! Введенное число должно быть от 1 до 10.\n");
						return 1;
					default:
						break;
				}
				break;
			case 'a':
				long int result;
				switch(a_func(x, &result)) {
						case NULL_POINTER:
							printf("Невалидный указатель для записи результата.\n");
							return 1;
						case OUT_OF_RANGE:
							printf("Число должно быть натуральным.\n");
							return 1;
						case OVERFLOW:
							printf("Ошибка! Переполнение ячейки памяти.\n");
							return 1;
						case SUCCESS:
							printf("Сумма всех натуральных чисел от 1 до %d - %ld \n", x, result);
                    		break;
				}
				break;
			case 'f':
				long long int res;
				switch(f_func(x, &res)) {
 						case NULL_POINTER:
							printf("Невалидный указатель для записи результата.\n");
							return 1;
						case OUT_OF_RANGE:
							printf("Число должно быть натуральным.\n");
							return 1;
						case OVERFLOW:
							printf("Ошибка! Переполнение ячейки памяти.\n");
							return 1;
						case SUCCESS:
							printf("Факториал числа %d - %lld \n", x, res);
                    		break;
				}
				break;
			default:
				printf("Такого флага не существует\n");
				return 1;
			}
	}
	return 0;
}

