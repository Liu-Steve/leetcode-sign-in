#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef pair<ll, int> p;

class Solution {
public:
    int shortestSubarray(const vector<int>& nums, int k)
    {
        int len = nums.size();
        p q[len + 1];
        int begin = 0;
        int sz = 0;
        int res = 0x7fffffff;
        ll sum = 0;
        q[0].first = sum;
        q[0].second = -1;
        sz++;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            while (sz && q[(begin + sz - 1) % (len + 1)].first >= sum) {
                sz--;
            }
            while (sz && sum - q[begin].first >= k) {
                res = min(res, i - q[begin].second);
                begin++;
                begin %= len + 1;
                sz--;
            }
            q[(begin + sz) % (len + 1)].first = sum;
            q[(begin + sz) % (len + 1)].second = i;
            sz++;
        }
        if (res == 0x7fffffff)
            return -1;
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> nums = {77,19,35,10,-14};
    cout << s.shortestSubarray(nums, 19) << endl;
    return 0;
}