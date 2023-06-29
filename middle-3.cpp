#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int len = 0;
        int head = 0;
        int hm[96];
        for (int i = 0; i < 96; ++i)
            hm[i] = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            int ch = s[i] - ' ';
            if (hm[ch] == -1)
            {
                hm[ch] = i;
                len++;
                ans = max(ans, len);
                continue;
            }
            len = i - hm[ch];
            for (int j = hm[ch] - 1; j >= head; --j)
                hm[s[j] - ' '] = -1;
            head = hm[ch] + 1;
            hm[ch] = i;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.lengthOfLongestSubstring("bpfbhmipx") << endl;
    return 0;
}
