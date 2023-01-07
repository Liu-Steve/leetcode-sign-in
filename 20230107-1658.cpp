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
    int minOperations(vector<int> &nums, int x)
    {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        int sl = 0;
        int sr = 0;
        int ret = 0x7fffffff;
        for (r = len - 1; r >= 0; --r)
        {
            if (sr >= x)
                break;
            sr += nums[r];
        }
        if (sr < x)
            return -1;
        if (r == -1 && sr == x)
            return len;
        while (1)
        {
            if (sl + sr == x)
                ret = min(ret, l + len - 1 - r);
            ++r;
            if (r == len)
                break;
            sr -= nums[r];
            while (sl + sr < x)
            {
                sl += nums[l];
                ++l;
            }
        }
        return ret == 0x7fffffff ? -1 : ret;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 1, 1, 1, 1, 4};
    cout << s.minOperations(v1, 5) << endl;
    vi v2 = {1, 1, 4, 2, 3};
    cout << s.minOperations(v2, 5) << endl;
    vi v3 = {5, 6, 7, 8, 9};
    cout << s.minOperations(v3, 4) << endl;
    vi v4 = {3, 2, 20, 1, 1, 3};
    cout << s.minOperations(v4, 10) << endl;
    vi v5 = {500, 1, 4, 2, 3};
    cout << s.minOperations(v5, 500) << endl;
    return 0;
}