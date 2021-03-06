bool isValid(char* s) {
    int n = 0, cap = 100;
    char *stack = malloc(cap * sizeof(char));
    while (*s != '\0') {
        switch(*s) {
        case '(':
        case '[':
        case '{':
            if (n + 1 >= cap) {
                cap *= 2;
                stack = realloc(stack, cap);
            }
            stack[n++] = *s;
            break;
        case ')':
            if (stack[--n] != '(') return false;
            break;
        case ']':
            if (stack[--n] != '[') return false;
            break;
        case '}':
            if (stack[--n] != '{') return false;
            break;
        default:
            return false;
        }
        s++;
    }

    return n == 0;
}
