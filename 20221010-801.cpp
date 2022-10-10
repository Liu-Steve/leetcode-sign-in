#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int lastC = 1, lastNC = 0;
        int n = nums1.size();
        int c, nc;
        for (int i = 1; i < n; ++i)
        {
            if (nums1[i] <= nums1[i - 1] || nums2[i] <= nums2[i - 1])
            {
                c = lastNC + 1;
                nc = lastC;
            }
            else if (nums1[i] <= nums2[i - 1] || nums2[i] <= nums1[i - 1])
            {
                c = lastC + 1;
                nc = lastNC;
            }
            else
            {
                c = min(lastC, lastNC) + 1;
                nc = min(lastC, lastNC);
            }
            lastC = c;
            lastNC = nc;
        }
        return min(lastC, lastNC);
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v1 = {1, 3, 5, 4};
    vector<int> v2 = {1, 2, 3, 7};
    cout << s.minSwap(v1, v2);
    return 0;
}