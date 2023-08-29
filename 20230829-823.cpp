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

class Solution {
public:
    int numFactoredBinaryTrees(vi& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<ll> dp(n, 1);
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = 0;
            int r = i - 1;
            while (l <= r)
            {
                ll mul = (ll)arr[l] * arr[r];
                if (mul < arr[i])
                {
                    l++;
                    continue;
                }
                if (mul > arr[i])
                {
                    r--;
                    continue;
                }
                dp[i] += (dp[l] * dp[r] * ((l != r) + 1)) % MOD;
                dp[i] %= MOD;
                l++;
                r--;
            }
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
