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
    int minOperations(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i - 1] >= nums[i])
            {
                sum += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return sum;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 1, 1};
    cout << s.minOperations(v1) << endl;
    vi v2 = {1, 5, 2, 4, 1};
    cout << s.minOperations(v2) << endl;
    vi v3 = {8};
    cout << s.minOperations(v3) << endl;
    return 0;
}