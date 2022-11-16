#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution
{
public:
    bool isIdealPermutation(const vi &nums)
    {
        int buff = 0, maxn = 0, len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            int n = nums[i];
            if (n < maxn)
                return false;
            maxn = maxn > buff ? maxn : buff;
            buff = n;
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 0, 2};
    cout << s.isIdealPermutation(v1) << endl;
    vi v2 = {1, 2, 0};
    cout << s.isIdealPermutation(v2) << endl;
    return 0;
}