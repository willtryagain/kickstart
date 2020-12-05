#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int SIZE = 2e5 + 1;

int lps[SIZE];

void lps_finder(string pat, int m) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp_search(string pat, string txt) {
    int n = txt.length();
    int m = pat.length();
    vector<int> indices;
    lps_finder(pat, m);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            indices.push_back(i-j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return indices;
} 



int main(int argc, char const *argv[]) {
    int t = 1;
    // cin>> t;
    while (t--) {
        b();
        // cout<< b();
        // cout<<endl;
    }
    
    
    // d();
    return 0;
}
 

