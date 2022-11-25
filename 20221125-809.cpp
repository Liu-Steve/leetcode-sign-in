#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int len1 = s.size();
        int res = 0;
        for (string &sw : words)
        {
            int p1 = 0;
            int p2 = 0;
            int len2 = sw.size();
            int loop1 = 1;
            int loop2 = 1;
            while (p1 < len1 && p2 < len2)
            {
                loop1 = loop2 = 1;
                while (p1 + 1 < len1 && s[p1] == s[p1 + 1])
                {
                    p1++;
                    loop1++;
                }
                while (p2 + 1 < len2 && sw[p2] == sw[p2 + 1])
                {
                    p2++;
                    loop2++;
                }
                if (s[p1] != sw[p2] || loop1 < loop2 || (loop1 == 2 && loop2 == 1))
                    break;
                p1++;
                p2++;
            }
            res += (p1 == len1 && p2 == len2);
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"hello", "hi", "helo"};
    cout << s.expressiveWords("heeellooo", v1) << endl;
    vs v2 = {"zzyy", "zy", "zyy"};
    cout << s.expressiveWords("zzzzzyyyyy", v2) << endl;
    return 0;
}