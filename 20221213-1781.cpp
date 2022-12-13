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
    int beautySum(string s)
    {
        int len = s.size();
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            vector<int> cnt(26);
            for (int j = i; j < len; ++j)
            {
                cnt[s[j] - 'a']++;
                int mx = 0;
                int mi = 0x7fff;
                for (int k = 0; k < 26; ++k)
                {
                    if (cnt[k])
                    {
                        mx = max(mx, cnt[k]);
                        mi = min(mi, cnt[k]);
                    }
                }
                res += mx - mi;
            }
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.beautySum("aabcb") << endl;
    cout << s.beautySum("aabcbaa") << endl;
    return 0;
}