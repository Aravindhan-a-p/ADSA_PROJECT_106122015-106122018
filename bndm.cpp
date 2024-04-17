#include <bits/stdc++.h>
using namespace std;

void BNDM(const string& x, int plen, const string& y, int tlen) {
    const int ASIZE = 256; //ASCII values
    vector<int> B(ASIZE, 0);

    // Pre processing
    int s = 1;
    for (int i = plen - 1; i >= 0; i--) {
        B[static_cast<unsigned char>(x[i])] |= s;
        s <<= 1;
    }

    // Searching phase
    int j = 0;
    while (j <= tlen - plen) {
        int i = plen - 1;
        int last = plen;
        int d = ~0;
        while (i >= 0 && d != 0) {
            d &= B[static_cast<unsigned char>(y[j + i])];
            i--;
            if (d != 0) {
                if (i >= 0)
                    last = i + 1;
                else
                    cout << "Pattern found at index: " << j << endl;
            }
            d <<= 1;
        }
        j += last;
    }
}

int main() {
    string text,pattern;
    cout<<"Enter the text string:"<<endl;
    cin>>text;
    cout<<endl<<"Enter the pattern string:"<<endl;
    cin>>pattern;

    BNDM(pattern, pattern.size(), text, text.size());

    return 0;
}
