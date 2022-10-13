#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int sign = 0;
        int full = 0;
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            full |= 1 << i;
            sign |= 1 << arr[i];
            if (full == sign)
            {
                ret ++;
                full = 0;
                sign = 0;
            }
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v = {1,0,2,3,4};
    cout << s.maxChunksToSorted(v) << endl;
    return 0;
}