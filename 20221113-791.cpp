#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

char seq[26];

inline bool cmp(char c1, char c2)
{
    return seq[c1 - 'a'] < seq[c2 - 'a'];
}

class Solution
{
public:
    string customSortString(string order, string s)
    {
        memset(seq, 26, sizeof(seq));
        int len = order.size();
        for (int i = 0; i < len; ++i)
        {
            seq[order[i] - 'a'] = i;
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.customSortString("hdjksf", "idhcvbdfhvcdfjsdfsd") << endl;
    return 0;
}