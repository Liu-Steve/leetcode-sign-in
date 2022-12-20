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
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int num_max = 0;
        for (int num : nums)
            num_max = max(num, num_max);
        int l = 0;
        int r = num_max;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            int op = 0;
            for (int num : nums)
                op += (num - 1) / m;
            if (op > maxOperations)
                l = m;
            else
                r = m;
        }
        return r;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {9};
    cout << s.minimumSize(v1, 2) << endl;
    vi v2 = {2, 4, 8, 2};
    cout << s.minimumSize(v2, 4) << endl;
    vi v3 = {7, 17};
    cout << s.minimumSize(v3, 2) << endl;
    return 0;
}