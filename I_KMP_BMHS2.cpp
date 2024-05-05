#include <bits/stdc++.h>
using namespace std;

void ComputeNext(const string& pattern, vector<int>& next) {
    int m = pattern.size();
    int j = -1;
    next[0] = -1;

    for (int i = 1; i < m; ++i) {
        while (j >= 0 && pattern[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (pattern[i] == pattern[j + 1]) {
            ++j;
        }
        next[i] = j;
    }
}

void computeSkipTable(string p, int plen, int skip[256]) {
    for (int i = 0; i < 256; ++i) {
        skip[i] = plen;
    }
    for (int i = 0; i < plen - 1; ++i) {
        skip[p[i]] = plen - i - 1;
    }
}

void ImprovedSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next(m, 0);
    ComputeNext(pattern, next);

    int skip[256];
    computeSkipTable(pattern, m, skip);

    int i = 0; // index for text string
    int j = 0; // index for pattern string
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at position: " << i - j << endl;
            j = next[j - 1] + 1; // Move to the next possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = next[j - 1] + 1; // Using the improved next value
            else
                i++;
        }
        if (i < n && j < m && skip[text[i]] > j) {
            i = i - j + skip[text[i]];
            j = 0;
        }
    }
}

int main() {
    string text,pattern;
    cout<<endl<<"Enter the text string:"<<endl;
    cin>>text;
    cout<<endl<<"Enter the pattern string:"<<endl;
    cin>>pattern;
    ImprovedSearch(text, pattern);

    return 0;
}