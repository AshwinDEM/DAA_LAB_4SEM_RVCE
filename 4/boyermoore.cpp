#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#define ALPHABET_SIZE 256

vector<int> shift_table(ALPHABET_SIZE);
vector<int> suffix_table(ALPHABET_SIZE);

void pre_process(string pattern) {
    int i, j;
    shift_table.resize(ALPHABET_SIZE, pattern.size());

    for (i = 0; i < pattern.size() - 1; i++) {
        shift_table[pattern[i]] = pattern.size() - i - 1;
    }

    for (i = pattern.size() - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (pattern[j] == pattern[i]) {
                suffix_table[i] = i - j;
                break;
            }
        }
        if (j == i) {
            suffix_table[i] = pattern.size();
        }
    }
}

int boyer_moore(string text, string pattern) {
    int i, j, k;
    pre_process(pattern);
    i = pattern.size() - 1;
    while (i < text.size()) {
        k = i;
        j = pattern.size() - 1;
        while (j >= 0 && text[k] == pattern[j]) {
            k--;
            j--;
        }
        if (j < 0) {
            return k + 1;
        }
        i += std::max(suffix_table[j], shift_table[text[k]]);
    }
    return -1;
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    int pos = boyer_moore(text, pattern);
    if (pos != -1) {
        cout << "Pattern found at position: " << pos << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}