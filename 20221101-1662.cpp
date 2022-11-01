#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int s1 = -1, p1 = -1, s2 = -1, p2 = -1;
        int len1 = 0, len2 = 0;
        int size1 = word1.size(), size2 = word2.size();
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < size1; ++i)
            sum1 += word1[i].size();
        for(int i = 0; i < size2; ++i)
            sum2 += word2[i].size();
        if (sum1 != sum2)
            return false;
        while (sum1--)
        {
            p1++;
            p2++;
            if(p1 == len1)
            {
                p1 = 0;
                s1++;
                len1 = word1[s1].size();
            }
            if(p2 == len2)
            {
                p2 = 0;
                s2++;
                len2 = word2[s2].size();
            }
            if(word1[s1][p1] != word2[s2][p2])
                return false;
        }
        return true;
    }
};

int main() {
    io;
    Solution s;
    vector<string> v1 = {"abc", "d", "defg"}, v2 = {"abcddefg"};
    cout << s.arrayStringsAreEqual(v1, v2) << endl;
    return 0;
}