#include <stdio.h>
#include <string.h>
#include "task1.h"

int main() {
    char number; 
    char negative_number[sizeof(char) * 8 + 1];

    while (1) {
        scanf("%hd", &number);

        memset(negative_number, 0, sizeof(char) * 8 + 1);
        get_negative_number(number, negative_number);
        printf("%s\n", negative_number);
    }

    return 0;
}
