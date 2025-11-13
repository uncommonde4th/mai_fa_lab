#include <stdlib.h>

typedef struct {
    VECTOR_TYPE *data;
    size_t size;
    size_t capacity;
    VECTOR_TYPE (*CopyVoidPtr)(VECTOR_TYPE);
    void (*DeleteVoidPtr)(VECTOR_TYPE);
} Vector;

Vector create_vector(size_t initial_capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE));
// Удаление внутреннего содержимого вектора (data, size=0, capacity=0)
void erase_vector(Vector *v);
// Сравнение двух векторов (лексикографически)
// возвращает 1 — равны, 0 — не равны
int is_equal_vector(const Vector *v1, const Vector *v2);
// Копирование содержимого одного вектора в другой (существующий)
void copy_vector(Vector *dest, const Vector *src);
// Создание нового вектора в динамической памяти и копирование содержимого
Vector *copy_vector_new(const Vector *src);
// Добавление элемента в конец вектора
void push_back_vector(Vector *v, VECTOR_TYPE value);
// Удаление элемента по индексу
void delete_at_vector(Vector *v, size_t index);
// Получение элемента по индексу
VECTOR_TYPE get_at_vector(const Vector *v, size_t index);
// Освобождение памяти, занимаемой экземпляром вектора
void delete_vector(Vector *v);
