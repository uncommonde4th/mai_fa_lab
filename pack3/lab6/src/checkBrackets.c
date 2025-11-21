#include <stdlib.h>
#include <string.h>

int match(const char l, const char r) {
    return ((l == '(' && r == ')') || (l == '[' && r == ']') || 
            (l == '{' && r == '}') || (l == '<' && r == '>'));
}

int check_brackets(const char *str) {
    if (str == NULL) return 1;
    
    size_t len = strlen(str);
    char *stack = (char *)malloc(sizeof(char) * len);
    if (stack == NULL) return -1;
    
    int top = -1;
    int result = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (top == -1 || !match(stack[top--], c)) {
                result = 0;
                break;
            }
        }
    }
    
    if (result == 1 && top != -1) {
        result = 0;
    }
    
    free(stack);
    return result;
}
