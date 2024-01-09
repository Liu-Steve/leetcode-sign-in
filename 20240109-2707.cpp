#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
private:
    vi getNxt(string &pat)
    {
        int len = pat.size();
        vi nxt(len + 1);
        nxt[0] = -1;
        int i = 0;
        int j = -1;
        while (i < len)
        {
            if (j == -1 || pat[i] == pat[j])
            {
                ++i;
                ++j;
                nxt[i] = j;
            }
            else
                j = nxt[j];
        }
        return nxt;
    }

public:
    /**
     * KMP
     * 找到str中所有出现模式串pat的下标
     * 下标从0开始
     */
    void findAll(string &str, string &pat, vp &ans)
    {
        int len1 = str.size();
        int len2 = pat.size();
        int i = 0;
        int j = 0;
        vi nxt = getNxt(pat);
        while (i < len1 && j < len2)
        {
            if (j == -1 || str[i] == pat[j])
            {
                i++;
                j++;
            }
            else
                j = nxt[j];
            if (j >= len2)
            {
                ans.emplace_back(pr{i - j, pat.size()});
                // j = 0;  // 子串不可以重复
                j = nxt[j]; // 子串可以重复
            }
        }
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        vp ans;
        for (string pat : dictionary)
            findAll(s, pat, ans);
        sort(ans.begin(), ans.end());
        int n = s.size();
        vi dp(n + 1, 0);
        int p = ans.size() - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = dp[i + 1];
            while (p >= 0 && ans[p].first == i)
            {
                auto [l, len] = ans[p];
                dp[l] = max(dp[l], dp[l + len] + len);
                p--;
            }
        }
        return n - dp[0];
    }
};

int main()
{
    io;
    return 0;
}
