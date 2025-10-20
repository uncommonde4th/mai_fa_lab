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
    char dest[20];
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
    
    return 0;
}

