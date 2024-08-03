#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

int shift_table[ALPHABET_SIZE];
int suffix_table[ALPHABET_SIZE];

void pre_process(const char* pattern) {
    int i, j;
    int pattern_length = strlen(pattern);

    // Initialize shift_table with pattern length
    for (i = 0; i < ALPHABET_SIZE; i++) {
        shift_table[i] = pattern_length;
    }

    // Fill shift_table with the actual shift values
    for (i = 0; i < pattern_length - 1; i++) {
        shift_table[(unsigned char)pattern[i]] = pattern_length - i - 1;
    }

    // Compute suffix_table
    for (i = pattern_length - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (pattern[j] == pattern[i]) {
                suffix_table[i] = i - j;
                break;
            }
        }
        if (j == i) {
            suffix_table[i] = pattern_length;
        }
    }
}

int boyer_moore(const char* text, const char* pattern) {
    int i, j, k;
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    pre_process(pattern);
    i = pattern_length - 1;

    while (i < text_length) {
        k = i;
        j = pattern_length - 1;
        while (j >= 0 && text[k] == pattern[j]) {
            k--;
            j--;
        }
        if (j < 0) {
            return k + 1;
        }
        i += (suffix_table[j] > shift_table[(unsigned char)text[k]] ? suffix_table[j] : shift_table[(unsigned char)text[k]]);
    }
    return -1;
}

int main() {
    const char* text = "AABAACAADAABAAABAA";
    const char* pattern = "AABA";
    int pos = boyer_moore(text, pattern);
    if (pos != -1) {
        printf("Pattern found at position: %d\n", pos);
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}
