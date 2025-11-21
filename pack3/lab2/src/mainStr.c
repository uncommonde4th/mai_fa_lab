#include "../include/myVectorStr.h"
#include <stdio.h>
#include <string.h>

VECTOR_TYPE copy_str(VECTOR_TYPE str) {
    char *original = (char *)str;
    return (VECTOR_TYPE)strdup(original);
}

void delete_str(VECTOR_TYPE str) {
    free((char *)str);
}


int main() {
    Vector vec = create_vector(2, copy_str, delete_str);
    printf("Создан вектор. Размер: %zu, Вместимость: %zu\n", vec.size, vec.capacity);
    
    push_back_vector(&vec, (VECTOR_TYPE)"Hello");
    push_back_vector(&vec, (VECTOR_TYPE)"my");
    push_back_vector(&vec, (VECTOR_TYPE)"friend!");

    printf("После пушей. Размер: %zu, Вместимость: %zu\n", vec.size, vec.capacity);
 
    for (size_t i = 0; i < vec.size; i++) {
        printf("  vec[%zu] = %s\n", i, (char*)get_at_vector(&vec, i));
    }
    
    Vector vec2 = create_vector(1, copy_str, delete_str);
    copy_vector(&vec2, &vec);
    printf("После copy_vector. Размер vec2: %zu\n", vec2.size);
    erase_vector(&vec2);

    Vector *vec_copy = copy_vector_new(&vec);
    printf("Сравнение копии и оригинала: %d\n", is_equal_vector(&vec, vec_copy));
    
    delete_at_vector(&vec, 1);
    for (size_t i = 0; i < vec.size; i++) {
        printf("vec[%zu] = %s\n", i, (char*)get_at_vector(&vec, i));
    }
    
    printf("Сравнение после изменения: %d\n", is_equal_vector(&vec, vec_copy));
    
    erase_vector(&vec);

    if (vec_copy) {
        delete_vector(vec_copy);
    }
 
    return 0;
}
