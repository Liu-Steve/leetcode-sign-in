#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int len = arr.size();
        int ones = 0;
        for (int i : arr)
            ones += i;
        if (ones % 3 != 0)
            return {-1, -1};
        if (!ones)
            return {0, len - 1};

        int s1 = 0, s2 = 0, s3 = 0, cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (arr[i])
                cnt++;
            else
                continue;
            if (cnt == 1)
                s1 = i;
            if (cnt == ones / 3 + 1)
                s2 = i;
            if (cnt == 2 * ones / 3 + 1)
            {
                s3 = i;
                break;
            }
        }
        while (s3 < len)
        {
            if (arr[s1] != arr[s3] || arr[s2] != arr[s3])
                return {-1, -1};
            s1++;
            s2++;
            s3++;
        }
        return {s1 - 1, s2};
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v = {0, 0, 0};
    vector<int> res = s.threeEqualParts(v);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}