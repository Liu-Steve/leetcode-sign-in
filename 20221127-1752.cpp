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
    bool check(const vector<int> &nums)
    {
        int cnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            cnt += nums[i] > nums[(i + 1) % len];
        }
        return cnt <= 1;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {3, 4, 5, 1, 2};
    cout << s.check(v1) << endl;
    vi v2 = {2, 1, 3, 4};
    cout << s.check(v2) << endl;
    vi v3 = {1, 2, 3};
    cout << s.check(v3) << endl;
    return 0;
}