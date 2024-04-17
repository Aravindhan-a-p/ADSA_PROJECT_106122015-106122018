#include <bits/stdc++.h>
using namespace std;

void BMHS2Search(string t, int tlen, string p, int plen, int skip[256]) {
    int j, i = 0;
    if (plen == 1) { // Handle pattern length 1 separately
        while (i <= tlen - plen) {
            if (t[i] == p[0]) {
                cout << "Pattern found at position: " << i << endl;
            }
            i += skip[t[i]]; // Move according to skip value for current character
        }
    } else { // Handle pattern length greater than 1
        while (i <= tlen - plen) {
            for (j = plen - 1; j >= 0 && p[j] == t[j + i]; j--);
            if (j < 0) {
                cout << "Pattern found at position: " << i << endl;
                i += plen; // Corrected here
            } else {
                i += skip[t[i + plen - 1]]; // Move according to skip value for current character
            }
        }
    }
}

void computeSkipTable(string p, int plen, int skip[256]) {
    // Initialize skip table with default value (plen)
    for (int i = 0; i < 256; ++i) {
        skip[i] = plen;
    }
    // Populate skip table based on the pattern
    for (int i = 0; i < plen - 1; ++i) {
        skip[p[i]] = plen - i - 1;
    }
}

int main() {
    string text,pattern;
    cout<<"Enter the text string:"<<endl;
    cin>>text;
    cout<<endl<<"Enter the pattern string:"<<endl;
    cin>>pattern;

    int skip[256]; // Skip table holds skip values for each character

    // Compute skip table for the pattern
    computeSkipTable(pattern, pattern.length(), skip);

    // Perform pattern search
    BMHS2Search(text, text.length(), pattern, pattern.length(), skip);

    return 0;
}
