#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ALPHABET_SIZE 256

void preHorspool(string pattern, int m, vector<int> &shift)
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

void horspool(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> shift(ALPHABET_SIZE);
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
            cout << "Pattern found at index " << i << endl;
            i += shift[text[i + m - 1]];
        }
        else
        {
            i += shift[text[i + m - 1]];
        }
    }
}

int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";
    horspool(text, pattern);
    return 0;
}