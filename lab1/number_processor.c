#include <stdio.h>
#include <string.h>

int main(){
	char flag[3];
	char num_str[25];
	int num_int;

	printf("Возможные флаги:\n\n");
	printf("\t-h - выводит натуральные числа в пределах 100, кратные x\n");
	printf("\t-p - определяет является ли число x простым; является ли x составным\n");
	printf("\t-s - разделяет число x на отдельные цифры с/с с основанием 16\n");
	printf("\t-e - выводит таблицу степеней оснований от 1 до x (x не больше 10)\n");
	printf("\t-a - вычисляет сумму всех натуральных чисел от 1 до x\n");
	printf("\t-f - вычисляет факториал x\n\n");
	printf("Введите число и флаг:\n");
	scanf("%24s %2s", num_str, flag);
	
	if (flag[0] != '-' || flag[0] != '/'){
		printf("Флаг должен начинаться с '-' или '/'");
		return 1;
	}
	else{
		switch(flag[1]){
			case 'h':
				h_func();
				break;
			case 'p':
				p_func();
				break;
			case 's':
				s_func();
				break;
			case 'e':
				e_func();
				break;
			case 'a':
				a_func();
				break;
			case 'f':
				f_func();
				break;
			default:
				printf("Такого флага не существует\n");
			}
	}
	return 0;
}

