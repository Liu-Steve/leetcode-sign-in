#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; ++i)
        {
            if (s1[i] == s2[i])
                continue;
            if (idx1 == -1)
                idx1 = i;
            else if (idx2 == -1)
                idx2 = i;
            else
                return false;
        }
        if (idx1 == -1)
            return true;
        if (idx2 == -1)
            return false;
        if (s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1])
            return true;
        return false;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "abcd", s2 = "dcba";
    cout << s.areAlmostEqual(s1, s2) << endl;
    return 0;
}