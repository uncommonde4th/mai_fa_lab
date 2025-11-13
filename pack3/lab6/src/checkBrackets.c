#define SIZE_OF_STACK 1024

int match(const char l, const char r) {
    return ((l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}') || (l == '<' && r == '>'));
}

int check_brackets(const char *str) {
    char stack[SIZE_OF_STACK];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            if (top >= SIZE_OF_STACK - 1) {
                return -2;
            }
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (top == -1 || !match(stack[top--], c)) {
                return 0;
            }
        }
    }
    if (top == -1) { return 1; }
    else { return -1; }
}

