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
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> pre(n + 1), dp(n);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + stones[i];
        for (int i = n - 2; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                dp[j] = max(pre[j + 1] - pre[i + 1] - dp[j], pre[j] - pre[i] - dp[j - 1]);
        return dp[n - 1];
    }
};

int main()
{
    io;
    return 0;
}
