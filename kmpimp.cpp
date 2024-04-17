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

vector<int> KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next(m, 0);
    ComputeNext(pattern, next);

    vector<int> matches;
    int i = 0; // index for text string
    int j = 0; // index for pattern string
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = next[j - 1] + 1; // Move to the next possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = next[j - 1] + 1; // Using the improved next value
            else
                i++;
        }
    }
    return matches;
}

int main() {
    string text,pattern;
    cout<<"Enter the text string:"<<endl;
    cin>>text;
    cout<<endl<<"Enter the pattern string:"<<endl;
    cin>>pattern;
    vector<int> matches = KMPSearch(text, pattern);

    if (!matches.empty()) {
        for (int pos : matches) {
            cout << "Pattern found at position: ";
            cout << pos << " ";
            cout<<endl;
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
