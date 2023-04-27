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
typedef unordered_map<ll, int> memory;

class Solution
{
private:
    bool isFront(const string &s1, const string &s2)
    {
        if (s2.size() - s1.size() != 1)
            return false;
        int bias = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == s2[i + bias])
                continue;
            if (bias == 0)
            {
                bias++;
                --i;
            }
            else
                return false;
        }
        return true;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &s1, const string &s2)
             { return s1.size() < s2.size(); });
        vector<vector<int>> nxt(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isFront(words[i], words[j]))
                    nxt[i].emplace_back(j);
        vector<int> dp(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int mx = 1;
            for (int nx : nxt[i])
                mx = max(mx, dp[nx] + 1);
            dp[i] = mx;
            ans = max(ans, mx);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"qyssedya", "pabouk", "mjwdrbqwp", "vylodpmwp", "nfyqeowa", "pu", "paboukc", "qssedya", "lopmw", "nfyqowa", "vlodpmw", "mwdrqwp", "opmw", "qsda", "neo", "qyssedhyac", "pmw", "lodpmw", "mjwdrqwp", "eo", "nfqwa", "pabuk", "nfyqwa", "qssdya", "qsdya", "qyssedhya", "pabu", "nqwa", "pabqoukc", "pbu", "mw", "vlodpmwp", "x", "xr"};
    cout << s.longestStrChain(v1) << endl;
    return 0;
}
