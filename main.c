#include <stdio.h>

int main() {
    char memory[100] = { 0 };
    char* counter_ptr = &memory;
    FILE* file;
    char c;

    file = fopen("main.bl", "r");
    if (file == NULL) {
        printf("Cannot open file \n");
        return 0;
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == '[') {
            ++(*counter_ptr);
        }
        else if (c == ']') {
            --(*counter_ptr);
        }
        else if (c == '*') {
            *counter_ptr *= 2;
        }
        else if (c == ',') {
            *counter_ptr *= 3;
        }
        else if (c == '(') {
            ++(counter_ptr);
        }
        else if (c == ')') {
            --(counter_ptr);
        }
        else if (c == '.') {
            printf("%c", *counter_ptr);
        }
        else if (c == '%') {
            memset(memory, 0, sizeof(memory));
        }
    }
    fclose(file);
    return 0;
}
