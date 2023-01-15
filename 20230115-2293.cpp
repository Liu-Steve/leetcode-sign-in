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
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        int len = nums.size();
        while (len > 1)
        {
            len >>= 1;
            for (int i = 0; i < len; ++i)
                nums[i] = (i & 1)
                              ? max(nums[2 * i], nums[2 * i + 1])
                              : min(nums[2 * i], nums[2 * i + 1]);
        }
        return nums[0];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 3, 5, 2, 4, 8, 2, 2};
    cout << s.minMaxGame(v1) << endl;
    vi v2 = {3};
    cout << s.minMaxGame(v2) << endl;
    return 0;
}