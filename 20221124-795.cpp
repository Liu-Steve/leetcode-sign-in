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

class Solution
{
public:
    int numSubarrayBoundedMax(const vector<int> &nums, int left, int right)
    {
        int left1 = -1;
        int left2 = -1;
        int res = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            int n = nums[i];
            if (n > right)
            {
                left2 = i;
                left1 = -1;
            }
            else if (n >= left)
            {
                left1 = i;
            }
            if (left1 != -1)
            {
                res += left1 - left2;
            }
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {2, 1, 4, 3};
    cout << s.numSubarrayBoundedMax(v1, 2, 3) << endl;
    vi v2 = {2, 9, 2, 5, 6};
    cout << s.numSubarrayBoundedMax(v2, 2, 8) << endl;
    return 0;
}