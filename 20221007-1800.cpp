#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int maxs = 0;
        int last = 0;
        int sum = 0;
        for (int num : nums)
        {
            if (num > last)
                sum += num;
            else
                sum = num;
            last = num;
            maxs = max(maxs, sum);
        }
        return maxs;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v;
    // v = {10, 20, 30, 5, 10, 50};
    // v = {10, 20, 30, 40, 50};
    // v = {12, 17, 15, 13, 10, 11, 12};
    // v = {100, 10, 1};
    v = {9, 10, 10, 11, 5};
    cout << s.maxAscendingSum(v);
    return 0;
}