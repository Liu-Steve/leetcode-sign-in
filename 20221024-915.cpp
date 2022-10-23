#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

// class Solution {
// public:
//     int partitionDisjoint(vector<int>& nums) {
//         vector<int> s = vector<int>(nums);
//         sort(s.begin(), s.end());
//         int len = s.size();
//         long long s1 = 0, s2 = 0;
//         for(int i = 0; i < len; ++i)
//         {
//             s1 += nums[i];
//             s2 += s[i];
//             if (s1 == s2)
//                 return i + 1;
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int partitionDisjoint(const vector<int> &nums)
    {
        int mx = nums[0], next_max = nums[0], left = 0, len = nums.size();
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] < mx)
            {
                left = i;
                mx = next_max;
            }
            next_max = max(nums[i], next_max);
        }
        return left + 1;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> nums = {32, 57, 24, 19, 0, 24, 49, 67, 87, 87};
    cout << s.partitionDisjoint(nums) << endl;
    return 0;
}