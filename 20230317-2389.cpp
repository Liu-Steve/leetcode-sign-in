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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        int dp[n + 2];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i - 1] + nums[i - 1];
        dp[n + 1] = INT32_MAX;
        vector<int> ans(m);
        for (int i = 0; i < m; ++i)
        {
            int l = 0;
            int r = n + 1;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if (dp[mid] <= queries[i])
                    l = mid;
                else
                    r = mid;
            }
            ans[i] = l;
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