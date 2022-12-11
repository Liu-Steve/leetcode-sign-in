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
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (vector<int> &c : cuboids)
            sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size(), f[n];
        for (int i = 0; i < n; ++i)
        {
            f[i] = 0;
            for (int j = 0; j < i; ++j)
                // 排序后，cuboids[j][0] <= cuboids[i][0] 恒成立
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    f[i] = max(f[i], f[j]); // cuboids[j] 可以堆在 cuboids[i] 上
            f[i] += cuboids[i][2];
        }
        return *max_element(f, f + n);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}