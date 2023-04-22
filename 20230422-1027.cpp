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

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        const int bias = 500;
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        int ans = 0;
        for (int i = 1; i < n; ++i)
            for (int j = i - 1; j >= 0; --j)
            {
                int d = nums[j] - nums[i] + bias;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
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