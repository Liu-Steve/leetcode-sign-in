#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int len = nums.size();
        int sum[2] = {0, 0};
        for (int i = 1; i < len; ++i)
            sum[i & 1] += nums[i];
        int ans = (sum[0] == sum[1]);
        for (int i = 1; i < len; ++i)
        {
            sum[i & 1] -= nums[i];
            sum[i & 1] += nums[i - 1];
            ans += (sum[0] == sum[1]);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {2, 1, 6, 4};
    cout << s.waysToMakeFair(v1) << endl;
    vi v2 = {1, 1, 1};
    cout << s.waysToMakeFair(v2) << endl;
    vi v3 = {1, 2, 3};
    cout << s.waysToMakeFair(v3) << endl;
    return 0;
}