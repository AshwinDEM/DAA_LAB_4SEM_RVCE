#include <stdio.h>

#define ALPHABET_SIZE 256

void preHorspool(char *pattern, int m, int *shift)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        shift[i] = m;
    }
    for (int i = 0; i < m - 1; i++)
    {
        shift[pattern[i]] = m - 1 - i;
    }
}

void horspool(char *text, int n, char *pattern, int m)
{
    int shift[ALPHABET_SIZE];
    preHorspool(pattern, m, shift);
    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j])
        {
            j--;
        }
        if (j < 0)
        {
            printf("Pattern found at index %d\n", i);
            i += shift[text[i + m - 1]];
        }
        else
        {
            i += shift[text[i + m - 1]];
        }
    }
}

