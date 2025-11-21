#include "../include/myVector.h"
#include <stdio.h>
#include <string.h>

VECTOR_TYPE copy_int(VECTOR_TYPE value) {
    return value;
}

void delete_int(VECTOR_TYPE value) {
    (void)value;
}

int main() {
    Vector vec = create_vector(2, copy_int, delete_int);
    printf("Создан вектор. Размер: %zu, Вместимость: %zu\n", vec.size, vec.capacity);
    
    push_back_vector(&vec, (VECTOR_TYPE)65);
    push_back_vector(&vec, (VECTOR_TYPE)43);
    push_back_vector(&vec, (VECTOR_TYPE)21);

    printf("После пушей. Размер: %zu, Вместимость: %zu\n", vec.size, vec.capacity);
 
    for (size_t i = 0; i < vec.size; i++) {
        printf("  vec[%zu] = %d\n", i, (int)get_at_vector(&vec, i));
    }
    
    Vector vec2 = create_vector(1, copy_int, delete_int);
    copy_vector(&vec2, &vec);
    printf("После copy_vector. Размер vec2: %zu\n", vec2.size);
    erase_vector(&vec2);

    Vector *vec_copy = copy_vector_new(&vec);
    printf("Сравнение копии и оригинала: %d\n", is_equal_vector(&vec, vec_copy));
    
    delete_at_vector(&vec, 1);
    for (size_t i = 0; i < vec.size; i++) {
        printf("vec[%zu] = %d\n", i, (int)get_at_vector(&vec, i));
    }
    
    printf("Сравнение после изменения: %d\n", is_equal_vector(&vec, vec_copy));
    
    erase_vector(&vec);

    if (vec_copy) {
        delete_vector(vec_copy);
    }
 
    return 0;
}
