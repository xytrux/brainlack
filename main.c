#include <stdio.h>

int main() {
    char c;
    int counter = 0;

    while ((c = getchar()) != EOF) {
        if (c == '[') {
            counter++;
        }
        else if (c == ']') {
            counter--;
        }
        else if (c == '*') { // Let's use '*' as the operator to multiply the counter by 2
            counter *= 2;
        }
        else if (c == ',') {
            counter *= 3;
        }
        else if (c == '.') { // '.' is the end character
            printf("%c", counter);
            counter = 0;
        }
    }

    return 0;
}
