#include <stdio.h>
#include "../include/functions.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
void *memchr(const void *str, int c, size_t n) {
    const unsigned char *ptr = (const unsigned char *)str;
    unsigned char symbol = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        if (ptr[i] == symbol) {
            return (void *)(ptr + i);
        }
    }
    return NULL;
}

// Сравнивает первые n байтов str1 и str2.
int memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *ptr1 = (const unsigned char *)str1;
    const unsigned char *ptr2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {
        if (ptr1[i] != ptr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Копирует n символов из src в dest.
void *memcpy(void *dest, const void *src, size_t n) {
    unsigned char *input = (unsigned char *)dest;
    const unsigned char *output = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        input[i] = output[i];
    }
    return (void *)input;
}

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *memset(void *str, int c, size_t n) {
    unsigned char *ptr = (unsigned char *)str;
    unsigned char symbol = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        ptr[i] = symbol;
    }
    return (void *)ptr;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
char *strncat(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) { return dest; }

    char *d = dest;

    while (*d != '\0') { d++; }
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        d[i] = src[i];
    }
    d[i] = '\0';
    
    return dest;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *strchr(const char *str, int c) {
    if (str == NULL) { return NULL; }

    const char *ptr = str;
    unsigned char symbol = (unsigned char)c;

    while (*ptr != '\0') {
        if (*ptr == symbol) {
            return (char *)ptr;
        }
        ptr++;
    }

    if (symbol == '\0') {
        return (char *)ptr;
    }

    return NULL;
}

// Сравнивает не более первых n байтов str1 и str2.
int strncmp(const char *str1, const char *str2, size_t n) {
    if (n == 0) { return 0; }

    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        if (str1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

// Копирует до n символов из строки, на которую указывает src, в dest.
char *strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) { return dest; }

    char *d = dest;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    while (i < n) {
        dest[i] = '\0';
        i++;
    }

    return dest;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
size_t strcspn(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) { return 0; }

    size_t count = 0;
    for (const char *s1 = str1; *s1 != '\0'; s1++) {
        const char *s2 = str2;
        while (*s2 != '\0') {
            if (*s1 == *s2) {
                return count;
            }
            s2++;
        }
        count++;
    }

    return count;
}
/*
// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке.
char *strerror(int errnum) {

}
*/
// Вычисляет длину строки str, не включая завершающий нулевой символ.
size_t strlen(const char *str) {
    if (str == NULL) { return 0; }

    const char *ptr = str;
    size_t c = 0;

    while (*ptr != '\0') {
        c++;
        ptr++;
    }
    return c;
}

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *strpbrk(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) { return NULL; }

    const char *ptr1 = str1;

    while (*ptr1 != '\0') {
        const char *ptr2 = str2;
        while (*ptr2 != '\0') {
            if (*ptr1 == *ptr2) {
                return (char *)ptr1;
            }
            ptr2++;
        }
        ptr1++;
    }

    return NULL;
}

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *strrchr(const char *str, int c) {
    if (str == NULL ) { return NULL; }

    const char *ptr = str;
    unsigned char symbol = (unsigned char)c;
    const char *last = NULL;

    while (*ptr != '\0') {
        if (*ptr == symbol) {
            last = ptr;
        }
        ptr++;
    }
    
    if (symbol == '\0') {
        return (char *)ptr;
    }

    return (char *)last;
}

// Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack
char *strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) { return NULL; }
    if (*needle == '\0') { return (char *)haystack; }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}

// Разбивает строку str на ряд токенов, разделенных delim.
char *strtok(char *str, const char *delim) {
   static char *next = NULL;

   if (str != NULL) { next = str; }
   if (next == NULL || *next == '\0') { return NULL; }

   char *start = next;
   while (*start != '\0') {
       const char *d = delim;
       while (*d != '\0') {
           if (*start == *d) { break; }
           d++;
       }
       if (*d == '\0') { break; }
       start++;
   }

   if (*start == '\0') {
       next = start;
       return NULL;
   }

   char *end = start;
   while (*end != '\0') {
       const char *d = delim;
       while (*d != '\0') {
           if (*end == *d) {
               *end = '\0';
               next = end + 1;
               return start;
           }
           d++;
       }
       end++;
   }

   next = end;
   return start;
}
