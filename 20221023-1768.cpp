#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret = word1 + word2;
        int len1 = word1.size();
        int len2 = word2.size();
        int len_min = min(len1, len2);
        for (int i = 0; i < len_min; ++i)
        {
            ret[2*i] = word1[i];
            ret[2*i + 1] = word2[i];
        }
        if (len1 > len2)
            for (int i = len_min; i < len1; ++i)
                ret[i + len_min] = word1[i];
        else if (len1 < len2)
            for (int i = len_min; i < len2; ++i)
                ret[i + len_min] = word2[i];
        return ret;
    }
};

int main() {
    io;
    Solution s;
    cout << s.mergeAlternately("abc", "pqr") << endl;
    cout << s.mergeAlternately("ab", "pqrs") << endl;
    cout << s.mergeAlternately("abcd", "pq") << endl;
    return 0;
}