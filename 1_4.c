#include <stdio.h>
#include <string.h>
#include "task1.h"

int main() {
    char bin[257];
    char hex[65];

    while (1) {
        memset(bin, '\0', 257);
        memset(hex, '\0', 65);

        char c;

        int index = 0;

        while ((c = getchar()) != '\n') {
            hex[index++] = c;
        }

        hex_to_bin(hex, bin);

        printf("%s\n", bin);
    }
    return 0;
}
