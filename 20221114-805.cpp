#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

inline int log2_f(int p)
{
    float q = (float)(p << 1);
    return *(int *)&q >> 23 & 31;
}

class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int len = nums.size();
        int len_h = len >> 1;
        int nums_sum = 0;
        for (int i = 0; i < len; ++i) {
            nums[i] *= len;
            nums_sum += nums[i];
        }
        int avg = nums_sum / len;
        for (int i = 0; i < len; ++i) {
            nums[i] -= avg;
        }
        unordered_set<int> s;
        int lenp = 1 << len_h;
        int sum = 0;
        int pat = 0;
        for (int i = 1; i < lenp; ++i)
        {
            // 利用格雷码原理遍历
            int idxp = i & (-i);
            int idx = log2_f(idxp);
            sum += (pat & idxp) ? (-nums[idx]) : nums[idx];
            if(!sum)
                return true;
            s.insert(sum);
            pat ^= idxp;
        }
        lenp = 1 << (len - len_h);
        sum = 0;
        pat = 0;
        int full_pat = lenp - 1;
        for (int i = 1; i < lenp; ++i)
        {
            // 利用格雷码原理遍历
            int idxp = i & (-i);
            int idx = log2_f(idxp) + len_h;
            sum += (pat & idxp) ? (-nums[idx]) : nums[idx];
            pat ^= idxp;
            if(s.count(-sum) && pat != full_pat)
                return true;
        }
        return false;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v = {3,0};
    cout << s.splitArraySameAverage(v) << endl;
    return 0;
}