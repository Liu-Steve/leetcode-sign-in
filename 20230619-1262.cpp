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
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n + 1][3];
        dp[0][0] = 0;
        dp[0][1] = -1;
        dp[0][2] = -1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 3; ++j)
                dp[i][(j + nums[i - 1]) % 3] = max(
                    dp[i - 1][(j + nums[i - 1]) % 3],
                    (dp[i - 1][j] == -1 ? -1 : dp[i - 1][j] + nums[i - 1]));
        return dp[n][0];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {3, 6, 5, 1, 8};
    cout << s.maxSumDivThree(v1) << endl;
    return 0;
}
