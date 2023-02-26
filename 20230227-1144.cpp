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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int sum[2] = {0, 0};
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            int l = i == 0 ? INT32_MAX : nums[i - 1];
            int r = i == len - 1 ? INT32_MAX : nums[i + 1];
            int m = min(l, r);
            if (m <= nums[i])
                sum[i & 1] += nums[i] - m + 1;
        }
        return min(sum[0], sum[1]);
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {7, 4, 8, 9, 7, 7, 5};
    cout << s.movesToMakeZigzag(v1) << endl;
    return 0;
}