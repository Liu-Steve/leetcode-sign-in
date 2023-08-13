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
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        vi dp(n * 2 + 1);
        for (int i = 0; i < n; ++i)
            dp[i + 1] = dp[i] + nums[i];
        for (int i = 0; i < n; ++i)
            dp[n + i + 1] = dp[n + i] + nums[i];
        priority_queue<pr, vp, greater<pr>> q;
        int ans = INT32_MIN;
        q.emplace(0, 0);
        for (int i = 1; i <= 2 * n; ++i)
        {
            while (i - q.top().second > n)
                q.pop();
            ans = max(ans, dp[i] - q.top().first);
            q.emplace(dp[i], i);
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
