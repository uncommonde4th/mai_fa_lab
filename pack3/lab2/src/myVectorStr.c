#include "../include/myVectorStr.h"
// Доступ к вектору О(1)
// Добавление элемента О(N)


Vector create_vector(size_t initial_capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE)) {
     Vector v;

    v.size = 0;
    v.capacity = initial_capacity;
    v.CopyVoidPtr = CopyFunc;
    v.DeleteVoidPtr = DeleteFunc;

    if (initial_capacity > 0) {
        v.data = (VECTOR_TYPE*)malloc(v.capacity * sizeof(VECTOR_TYPE));
        if (v.data == NULL) {
            printf("Ошибка. Не удалось выделить память при создании вектора.\n");
            v.capacity = 0;
        }
    } else {
        v.data = NULL;
    }

    return v;
}

// Удаление внутреннего содержимого вектора (data, size=0, capacity=0)
void erase_vector(Vector *v) {
    if (v == NULL) {
        return;
    }

    if (v->DeleteVoidPtr != NULL && v->data != NULL) {
        for (size_t i = 0; i < v->size; i++) {
            v->DeleteVoidPtr(v->data[i]);
        }
    }

    if (v->data != NULL) {
        free(v->data);
        v->data = NULL;
    }

    v->size = 0;
    v->capacity = 0;
}

// Сравнение двух векторов (лексикографически) возвращает 1 — равны, 0 — не равны
int is_equal_vector(const Vector *v1, const Vector *v2) {
    if (v1 == NULL || v2 == NULL) {
        return (v1 == v2) ? 1 : 0;
    }

    if (v1->size != v2->size) {
        return 0;
    }

    for (size_t i = 0; i < v1->size; i++) {
        if (v1->data[i] != v2->data[i]) {
            return 0;
        }
    }

    return 1;
}

// Копирование содержимого одного вектора в другой (существующий)
void copy_vector(Vector *dest, const Vector *src) {
    if (dest == NULL || src == NULL || dest == src) {
        return;
    }
    
    VECTOR_TYPE (*oldCopyFunc)(VECTOR_TYPE) = dest->CopyVoidPtr;
    void (*oldDeleteFunc)(VECTOR_TYPE) = dest->DeleteVoidPtr;
    
    erase_vector(dest);
    
    dest->CopyVoidPtr = oldCopyFunc;
    dest->DeleteVoidPtr = oldDeleteFunc;

    if (src->size == 0) {
        return;
    }

    dest->data = (VECTOR_TYPE*)malloc(src->capacity * sizeof(VECTOR_TYPE));
    if (dest->data == NULL) {
        printf("Ошибка. не удалось выделить память при копировании вектора.\n");
        return;
    }

    dest->capacity = src->capacity;
    dest->size = src->size;

    for (size_t i = 0; i < src->size; i++) {
        if (dest->CopyVoidPtr != NULL) {
            dest->data[i] = dest->CopyVoidPtr(src->data[i]);
        } else {
            dest->data[i] = src->data[i];
        }
    }
}

// Создание нового вектора в динамической памяти и копирование содержимого
Vector *copy_vector_new(const Vector *src) {
    if (src == NULL) {
        return NULL;
    }

    Vector *v = (Vector*)malloc(sizeof(Vector));
    if (v == NULL) {
        printf("Ошибка. Не удалось выделить память для новой копии вектора.\n");
        return NULL;
    }

    v->size = src->size;
    v->capacity = src->capacity;
    v->CopyVoidPtr = src->CopyVoidPtr;
    v->DeleteVoidPtr = src->DeleteVoidPtr;

    if (src->capacity > 0) {
        v->data = (VECTOR_TYPE*)malloc(src->capacity * sizeof(VECTOR_TYPE));
        if (v->data == NULL) {
            printf("Ошибка. Не удалось выделить память для данных новой копии вектора.\n");
            free(v);
            return NULL;
        }

        for (size_t i = 0; i < src->size; i++) {
            if (v->CopyVoidPtr != NULL) {
                v->data[i] = v->CopyVoidPtr(src->data[i]);
            } else {
                v->data[i] = src->data[i];
            }
        }
    } else {
        v->data = NULL;
    }

    return v;
}

// Добавление элемента в конец вектора
void push_back_vector(Vector *v, VECTOR_TYPE value) {
    if (v == NULL) {
        return;
    }

    if (v->size >= v->capacity) {
        size_t newCapacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        VECTOR_TYPE *newData = (VECTOR_TYPE*)realloc(v->data, newCapacity * sizeof(VECTOR_TYPE));

        if (newData == NULL) {
            printf("Ошибка. Не удалось перевыделить память при добавлении нового элемента.\n");
            return;
        }

        v->data = newData;
        v->capacity = newCapacity;
    }

    if (v->CopyVoidPtr != NULL) {
        v->data[v->size] = v->CopyVoidPtr(value);
    } else {
        v->data[v->size] = value;
    }

    v->size++;
} 

// Удаление элемента по индексу
void delete_at_vector(Vector *v, size_t index) {
    if (v == NULL || v->data == NULL || index >= v->size) {
        return;
    }

    if (v->DeleteVoidPtr != NULL) {
        v->DeleteVoidPtr(v->data[index]);
    }

    for (size_t i = index; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }

    v->size--;
}

// Получение элемента по индексу
VECTOR_TYPE get_at_vector(const Vector *v, size_t index) {
     if (v == NULL || v->data == NULL || index >= v->size) {
        printf("Ошибка. NULL-вектор или неправильный индекс.\n");
        return (VECTOR_TYPE)0;
    }

    return v->data[index];
}

// Освобождение памяти, занимаемой экземпляром вектора
void delete_vector(Vector *v) {
    if (v == NULL) {
        return;
    }

    erase_vector(v);
    free(v);
}
