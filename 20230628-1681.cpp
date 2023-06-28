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
    int minimumIncompatibility(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = n / k;
        vector<int> dp(1 << n, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < (1 << n) - 1; ++i)
        {
            int cnt = __builtin_popcount(i);
            if (cnt % l > 0 || dp[i] == INT32_MAX)
                continue;
            int msk = (~i) & ((1 << n) - 1);
            for (int x = msk; x; x = (x - 1) & msk)
            {
                int mcnt = __builtin_popcount(x);
                if (mcnt != l)
                    continue;
                int vmax = INT32_MAX;
                int vmin = -1;
                for (int i = 0; i < n; ++i)
                {
                    if (((1 << i) & x) == 0)
                        continue;
                    if (vmin == -1)
                        vmin = nums[i];
                    if (vmax == nums[i])
                    {
                        vmax = -1;
                        break;
                    }
                    vmax = nums[i];
                }
                if (vmax == -1)
                    continue;
                dp[i | x] = min(dp[i | x], dp[i] + vmax - vmin);
            }
        }
        if (dp.back() == INT32_MAX)
            return -1;
        return dp.back();
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 2, 1, 4};
    cout << s.minimumIncompatibility(v1, 2) << endl;
    vi v2 = {6, 3, 8, 1, 3, 1, 2, 2};
    cout << s.minimumIncompatibility(v2, 4) << endl;
    vi v3 = {5, 3, 3, 6, 3, 3};
    cout << s.minimumIncompatibility(v3, 3) << endl;
    vi v4 = {13, 4, 7, 3, 3, 1, 12, 9, 11, 10, 13, 3, 12, 7};
    cout << s.minimumIncompatibility(v4, 7) << endl;
    return 0;
}
