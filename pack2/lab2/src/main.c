#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/functions.h"


int main() {
    // memchr
    char str1[] = "Hello, World!";
    assert(memchr(str1, 'W', 10) == str1 + 7);
    assert(memchr(str1, 'W', 4) == NULL);
    assert(memchr(str1, 'X', 13) == NULL);
    printf("memchr passed\n");

    // memcmp
    assert(memcmp("abc", "abc", 3) == 0);
    assert(memcmp("abcaaa", "abcbbb", 3) == 0);
    assert(memcmp("abc", "abd", 3) < 0);
    assert(memcmp("abd", "abc", 3) > 0);
    printf("memcmp passed\n");

    // memcpy
    char dest[30];
    assert(memcpy(dest, "World", 5) == dest);
    assert(memcmp(dest, "World", 5) == 0);
    assert(memcpy(dest, "Test", 0) == dest);
    assert(memcpy(dest, "World", 3) == dest);
    assert(memcmp(dest, "Wor", 3) == 0);
    printf("memcpy passed\n");

    // memset
    char buf[10];
    assert(memset(buf, 'a', 5) == buf);
    assert(memcmp(buf, "aaaaa", 5) == 0);
    assert(memset(buf, 'a', 0) == buf);
    assert(memset(buf, '\0', 3) == buf);
    assert(buf[0] == '\0' && buf[1] == '\0' && buf[2] == '\0');
    printf("memset passed\n");

    //strncat
    char dest1[20] = "Hello";
    assert(strncat(dest1, " World", 6) == dest1);
    assert(strcmp(dest1, "Hello World") == 0);
    char dest2[20] = "Test";
    assert(strncat(dest2, "123abc", 5) == dest2);
    assert(strcmp(dest2, "Test123ab") == 0);
    char dest3[20] = "Test";
    assert(strncat(dest3, "", 5) == dest3);
    assert(strcmp(dest3, "Test") == 0);
    printf("strncat passed\n");

    // strchr
    const char *str = "Hello World";
    assert(strchr(str, 'W') == str + 6);
    assert(strchr(str, 'X') == NULL);
    assert(strchr(str, '\0') == str + 11);
    printf("strchr passed\n");

    // strncmp
    assert(strncmp("Hello", "Hello", 5) == 0);
    assert(strncmp("Hello", "HellO", 5) > 0);
    assert(strncmp("Hello", "HellO", 4) == 0);
    printf("strncmp passed\n");

    // strncpy
    char dest4[20];
    assert(strncpy(dest4, "Hello", 5) == dest4);
    assert(strncmp(dest4, "Hello", 5) == 0);
    strncpy(dest4, "Hi", 5);
    assert(dest4[0] == 'H' && dest4[1] == 'i' && dest4[2] == '\0' && dest4[4] == '\0');
    strncpy(dest4, "Test", 4);
    assert(strncmp(dest4, "Test", 4) == 0);
    printf("strncpy passed\n");

    // strcspn
    assert(strcspn("Hello World", "aeiou") == 1);
    assert(strcspn("Hello", "xyz") == 5);
    assert(strcspn("Apple", "Aa") == 0);
    printf("strcspn passed\n");
    
    // strlen
    assert(strlen("Hello") == 5);
    assert(strlen("") == 0);
    assert(strlen("This is a longer string") == 23);
    printf("strlen passed\n");

    // strpbrk
    const char *str2 = "Hello World";
    assert(strpbrk(str2, "aeiou") == str2 + 1);
    assert(strpbrk(str2, "xyz") == NULL);
    assert(strpbrk(str2, "ol") == str2 + 2);
    printf("strpbrk passed\n");

    // strrchr
    const char *str3 = "Hello World";
    assert(strrchr(str3, 'l') == str3 + 9);
    assert(strrchr(str3, 'x') == NULL);
    assert(strrchr(str3, 'H') == str3);
    printf("strrchr passed\n");

    // strstr
    const char *str4 = "Hello World Programming";
    assert(strstr(str4, "World") == str4 + 6);
    assert(strstr(str4, "Python") == NULL);
    assert(strstr(str4, "") == str4);
    printf("strstr passed\n");

    // strtok
    char s1[] = "one,two,three";
    assert(strcmp(strtok(s1, ","), "one") == 0);
    assert(strcmp(strtok(NULL, ","), "two") == 0);
    assert(strcmp(strtok(NULL, ","), "three") == 0);
    assert(strtok(NULL, ",") == NULL);
    char s2[] = "a; b,c.d";
    assert(strcmp(strtok(s2, "; ,."), "a") == 0);
    assert(strcmp(strtok(NULL, "; ,."), "b") == 0);
    char s3[] = ",,,";
    assert(strtok(s3, ",") == NULL);
    printf("strtok passed\n");

    return 0;
}

