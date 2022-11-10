#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

inline bool f(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int len = s.size();
        int h_len = len / 2;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < h_len; ++i)
            if (f(s[i]))
                n1++;
        for (int i = h_len; i < len; ++i)
            if (f(s[i]))
                n2++;
        return n1 == n2;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.halvesAreAlike("book") << endl;
    return 0;
}