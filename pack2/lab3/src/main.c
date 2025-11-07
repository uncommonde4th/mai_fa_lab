#include "../include/functions.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *f = fopen("output.txt", "w");
    if (f == NULL) {
        printf("Не удалось создать файл\n");
        return 1;
    }

    char buffer[256];
    int len;

    printf("=== Проверка всех функций ===\n\n");

    // 1. %Ro - Римские числа
    printf("1. %%Ro - Римские числа:\n");
    overfprintf(f, "Римские: 1994 = %Ro, 58 = %Ro, 4 = %Ro\n", 1994, 58, 4);
    len = oversprintf(buffer, "Римские: 9=%Ro, 3999=%Ro", 9, 3999);
    printf("   %s\n", buffer);

    // 2. %Zr - Цекендорф
    printf("\n2. %%Zr - Цекендорф:\n");
    overfprintf(f, "Цекендорф: 13 = %Zr, 42 = %Zr\n", 13, 42);
    len = oversprintf(buffer, "Цекендорф: 1=%Zr, 10=%Zr", 1, 10);
    printf("   %s\n", buffer);

    // 3. %Cv - Из 10-чной (нижний регистр)
    printf("\n3. %%Cv - Из 10-чной (нижний регистр):\n");
    overfprintf(f, "Из 10-чной: 255(16)=%Cv, 100(2)=%Cv\n", 255, 16, 100, 2);
    len = oversprintf(buffer, "Из 10-чной: 255(16)=%Cv", 255, 16);
    printf("   %s\n", buffer);

    // 4. %CV - Из 10-чной (верхний регистр)
    printf("\n4. %%CV - Из 10-чной (верхний регистр):\n");
    overfprintf(f, "Из 10-чной: 255(16)=%CV, 1002(36)=%CV\n", 255, 16, 1002, 36);
    len = oversprintf(buffer, "Из 10-чной: 1002(36)=%CV", 1002, 36);
    printf("   %s\n", buffer);

    // 5. %to - В 10-чную (нижний регистр)
    printf("\n5. %%to - В 10-чную (нижний регистр):\n");
    overfprintf(f, "В 10-чную: ff(16)=%to, 1010(2)=%to\n", "ff", 16, "1010", 2);
    len = oversprintf(buffer, "В 10-чную: ff(16)=%to", "ff", 16);
    printf("   %s\n", buffer);

    // 6. %TO - В 10-чную (верхний регистр)
    printf("\n6. %%TO - В 10-чную (верхний регистр):\n");
    overfprintf(f, "В 10-чную: FF(16)=%TO, RU(36)=%TO\n", "FF", 16, "RU", 36);
    len = oversprintf(buffer, "В 10-чную: RU(36)=%TO", "RU", 36);
    printf("   %s\n", buffer);

    // 7. %mi - Дамп int
    printf("\n7. %%mi - Дамп int:\n");
    overfprintf(f, "Дамп int: 42=%mi, -1=%mi\n", 42, -1);
    len = oversprintf(buffer, "Дамп int: 42=%mi", 42);
    printf("   %s\n", buffer);

    // 8. %mu - Дамп unsigned int
    printf("\n8. %%mu - Дамп unsigned int:\n");
    overfprintf(f, "Дамп uint: 1234567=%mu\n", 1234567);
    len = oversprintf(buffer, "Дамп uint: 1234567=%mu", 1234567);
    printf("   %s\n", buffer);

    // 9. %mf - Дамп float
    printf("\n9. %%mf - Дамп float:\n");
    overfprintf(f, "Дамп float: 3.14=%mf\n", 3.14f);
    len = oversprintf(buffer, "Дамп float: 3.14=%mf", 3.14f);
    printf("   %s\n", buffer);

    // 10. %md - Дамп double
    printf("\n10. %%md - Дамп double:\n");
    overfprintf(f, "Дамп double: 100.0001=%md\n", 100.0001);
    len = oversprintf(buffer, "Дамп double: 100.0001=%md", 100.0001);
    printf("   %s\n", buffer);

    // 11. Обычные флаги printf
    printf("\n11. Обычные флаги printf:\n");
    overfprintf(f, "Обычные: %d %s %.2f\n", 42, "текст", 3.14159);
    len = oversprintf(buffer, "Обычные: %d %s", 100, "test");
    printf("   %s\n", buffer);

    // 12. Смешанные флаги
    printf("\n12. Смешанные флаги:\n");
    len = oversprintf(buffer, "Смешанно: число %d, римское %Ro, дамп %mi", 2023, 2023, 2023);
    printf("   %s\n", buffer);

    fclose(f);
    printf("\nВсе функции проверены! Результаты в output.txt\n");

    return 0;
}
