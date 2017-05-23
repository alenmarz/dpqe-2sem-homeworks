int dec_to_bin (int dig) {
    
    int bin = 0;

    for (int pow = 1; dig != 0; pow *= 10, dig >>= 1)
        bin = bin + (dig % 2) * pow;
   
    return bin;
}


void get_negative_number(char number, char * negative_number) {
    char position = sizeof(char) * 8 - 1;

    while (number != -1) {
        negative_number[position] = number % 2 == 0 ? '0': '1';

        --position;
        number >>= 1;
    }

    while (position > -1) {
        negative_number[position] = '1';
        --position;
    }
}


char TABLE[16] = {
    '0', '1', '2', '3',
    '4', '5', '6', '7',
    '8', '9', 'A', 'B',
    'C', 'D', 'E', 'F',
};


void bin_to_hex(char * bin, char * hex) {
    int length = strlen(bin);

    int index = 0;

    int current = 0;

    // size of current group of bits
    //   * can be 1-4 for first group
    //   * can be only 4 for others
    int group = length % 4 == 0 ? 4 : length % 4;

    while (index < length) {

        switch (group) {
            case 4:
                current = (current << 1) + bin[index++] - '0';
            case 3:
                current = (current << 1) + bin[index++] - '0';
            case 2:
                current = (current << 1) + bin[index++] - '0';
            case 1:
                current = (current << 1) + bin[index++] - '0';
        }

        hex[(index - 1) / 4] = TABLE[current];
        group = 4;
        current = 0;
    }
}


void hex_to_bin(char * hex, char * bin) {

    int length = strlen(hex) * 4;

    int index = 0;

    char current;

    int numeric_current;

    int divisor;

    while (index < length) {
        current = hex[index / 4];

        if ('0' <= current && current <= '9') {
            numeric_current = current - '0';
        } else {
            numeric_current = current - 'A' + 10;
        }

        divisor = 8;

        while (divisor > 0) {
            bin[index++] = numeric_current / divisor + '0';
            if (numeric_current >= divisor) {
                numeric_current -= divisor;
            }
            divisor >>= 1;
        }
    }
}

