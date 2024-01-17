#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char memory[100] = { 0 };
    char* counter_ptr = &memory;
    char c;
    int comment = 0;

    if (argc != 2) {
        printf("Usage: bl <filename>.bl\n");
        return 1;
    }

    char* filename = argv[1];
    char* file_extension = strrchr(filename, '.');

    if (file_extension == NULL || strcmp(file_extension, ".bl") != 0) {
        printf("Error: File must have a .bl extension\n");
        return 1;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }



    while ((c = fgetc(file)) != EOF) {
        if (c == ';') {
            comment = !comment;
        }
        else if (c == '[') {
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
        else if (c == '#') {
            *counter_ptr = 0;
        }
        else if (c == '@') {
            printf("%d\n", *counter_ptr);
        }
        else if (c == '/') {
            printf("\n");
        }
        else if (c == '&') {
            printf(" ", *counter_ptr);
        }
    }
    fclose(file);
    return 0;
}
