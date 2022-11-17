#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

const ll MOD = 1000000007;

class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        ll res = 0, two = 1;
        for (int i = 0; i < len; ++i)
        {
            res += two * (nums[i] - nums[len - i - 1]);
            res %= MOD;
            res += res < 0 ? MOD : 0;
            two <<= 1;
            two %= MOD;
            two += two < 0 ? MOD : 0;
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vi v = {2,1,3};
    cout << s.sumSubseqWidths(v) << endl;
    return 0;
}