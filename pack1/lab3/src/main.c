#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"


int main(int argc, char *argv[]){
	if (argc < 3){
            printf("Формат: %s <флаг> [числа]\n", argv[0]);
            return 1;
    }
    const char *flag = argv[1];
	
	if (flag[0] != '-' && flag[0] != '/'){
		printf("Флаг должен начинаться с '-' или '/'\n");
		return 1;
	}

    if (flag[1] == 'q' || flag[1] == 't') {
        if (argc != 6) {
            printf("Ошибка! Флаг -%c требует 4 числа для работы.\n", flag[1]);
            return 1;
        }

        double epsilon, a, b, c;
        char *endptr;
        
        epsilon = strtod(argv[2], &endptr);
        if (endptr == argv[2] || *endptr != '\0' || epsilon < 0) {
            printf("Ошибка ввода: неверное значение эпсилон.\n");
            return 1;
        }
        
        a = strtod(argv[3], &endptr);
        if (endptr == argv[3] || *endptr != '\0') {
            printf("Ошибка ввода: неверное значение первого коэффициента.\n");
            return 1;
        }
        
        b = strtod(argv[4], &endptr);
        if (endptr == argv[4] || *endptr != '\0') {
            printf("Ошибка ввода: неверное значение второго коэффициента.\n");
            return 1;
        }
        
        c = strtod(argv[5], &endptr);
        if (endptr == argv[5] || *endptr != '\0') {
            printf("Ошибка ввода: неверное значение третьего коэффициента.\n");
            return 1;
        }

        if (flag[1] == 'q') {
            double coefs[3] = {a, b, c};
            double permutations[6][3];
            int permutations_count = 0;
            
            for (int i = 0; i < 6; i++) {
                int is_new = 1;
                for (int j = 0; j < permutations_count; j++) {
                    if (double_abs(permutations[j][0] - coefs[0]) < epsilon &&
                        double_abs(permutations[j][1] - coefs[1]) < epsilon &&
                        double_abs(permutations[j][2] - coefs[2]) < epsilon) {
                        is_new = 0;
                        break;
                    }
                }
                
                if (is_new) {
                    permutations[permutations_count][0] = coefs[0];
                    permutations[permutations_count][1] = coefs[1];
                    permutations[permutations_count][2] = coefs[2];
                    permutations_count++;
                    
                    double root1, root2;
                    printf("\nСлучай a = %f, b = %f, c = %f.\n", coefs[0], coefs[1], coefs[2]);
                    
                    switch (q_func(epsilon, coefs[0], coefs[1],coefs[2], &root1, &root2)) {
                        case SUCCESS:
                            printf("Ответ: два решения - %f и %f.\n", root1, root2);
                            break;
                        case INF_ROOTS:
                            printf("Ответ: бесконечно много решений.\n");
                            break;
                        case NO_ROOTS:
                            printf("Ответ: нет решений.\n");
                            break;
                        case NOT_A_SQUARE_EQUATION:
                            printf("Ответ: уравнение не является квадратным. Решение равно %f.\n", root1);
                            break;
                        case NEGATIVE_DISCRIMINANT:
                            printf("Ответ: дискриминант отрицательный, нет действительных корней.\n");
                            break;
                        case NULL_POINTER:
                            printf("Ошибка! Невалидный указатель.\n");
                            return 1;
                        default:
                            break;
                    }
                }
                
                if (i % 2 == 0) {
                    double tmp = coefs[1];
                    coefs[1] = coefs[2];
                    coefs[2] = tmp;
                } else {
                    double tmp = coefs[0];
                    coefs[0] = coefs[1];
                    coefs[1] = coefs[2];
                    coefs[2] = tmp;
                }
            }
        } else {

            bool result;
            switch (t_func(epsilon, a, b, c, &result)) {
                case SUCCESS:
                    if (!result) {
                        printf("Числа могут являться длинами сторон прямоугольного треугольника\n");
                    } else {
                        printf("Числа не могут являться длинами сторон прямоугольного треугольника\n");
                    }
                    break;
                case INVALID_ARGUMENTS:
                    printf("Длины сторон треугольника должны быть положительными числами.\n");
                    break;
                case NULL_POINTER:
                    printf("Ошибка! Невалидный указатель.\n");
                    return 1;
                case OVERFLOW:
                    printf("Ошибка! Переполнение ячейки памяти.\n");
                    return 1;
                default:
                    break;
            }
        }
    } else if (flag[1] == 'm'){

        if (argc != 4) {
            printf("Ошибка! Флаг -m требует 2 числа для работы. \n");
            return 1;
        }

        char *endptr;
        long x_long, y_long;
        int x, y;

        x_long = strtol(argv[2], &endptr, 10);
        if (*endptr != '\0') {
            printf("Ошибка ввода числа: недопустимый символ в числе.\n");
            return 1;
        }
        if (x_long > INT_MAX || x_long < INT_MIN) {
            printf("Ошибка! Переполнение ячейки памяти.\n");
            return 1;
        }
        x = (int)x_long;

        y_long = strtol(argv[3], &endptr, 10);
        if (*endptr != '\0') {
            printf("Ошибка ввода числа: недопустимый символ в числе.\n");
            return 1;
        }
        if (y_long > INT_MAX || y_long < INT_MIN) {
            printf("Ошибка! Переполнение ячейки памяти.\n");
            return 1;
        }
        y = (int)y_long;

        bool result;

        switch (m_func(x, y, &result)) {
            case SUCCESS:
                if (!result) {
                    printf("Первое число кратно второму.\n");
                } else {
                    printf("Первое число не кратно второму.\n");
                }
                break;
            case INVALID_ARGUMENTS:
                printf("Ошибка! Для флага необходимы ненулевые числа.\n");
                return 1;
            case NULL_POINTER:
                printf("Ошибка! Невалидный указатель.\n");
                return 1;
            default:
                break;
        }

        return 0;
    
    } else {
        printf("Ошибка ввода: проверьте написание флага. \n");
        return 1;
    }

    return 0;
}


