#include <stdio.h>

int main() {
    char memory[100] = {0};
    char* counter_ptr = &memory;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '[') {
            ++(*counter_ptr);
        }
        else if (c == ']') {
            --(*counter_ptr);
        }
        else if (c == '*') {
            *counter_ptr*=2;
        }
        else if (c == ',') {
            *counter_ptr*=3;
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

    return 0;
}
