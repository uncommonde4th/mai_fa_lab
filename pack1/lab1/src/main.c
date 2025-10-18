#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../include/functions.h"

int main(int argc, char *argv[]){
	if (argc != 3){
            printf("Формат: %s <число> <флаг>\n", argv[0]);
            return 1;
    }

    long x_long = strtol(argv[1], NULL, 10);
    if (x_long > INT_MAX || x_long < INT_MIN){
            printf("Переполнение\n");
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
				h_func(x);
				break;
			case 'p':
				p_func(x);
				break;
			case 's':
				s_func(x);
				break;
			case 'e':
				e_func(x);
				break;
			case 'a':
				a_func(x);
				break;
			case 'f':
				f_func(x);
				break;
			default:
				printf("Такого флага не существует\n");
			}
	}
	return 0;
}

