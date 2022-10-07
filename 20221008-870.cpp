#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef struct st
{
    int num;
    int idx;
} N;

inline bool cmp(N n1, N n2)
{
    return n1.num < n2.num;
}

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums2.size();
        vector<int> n1(len);
        vector<N> n2(len);
        for (int i = 0; i < len; ++i)
        {
            n2[i].idx = i;
            n2[i].num = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        sort(n2.begin(), n2.end(), cmp);
        int p1 = 0, p2 = len - 1;
        for (int i = 0; i < len; ++i)
        {
            int big = nums1[i];
            if (big > n2[p1].num)
            {
                n1[n2[p1].idx] = big;
                p1++;
            }
            else
            {
                n1[n2[p2].idx] = big;
                p2--;
            }
        }
        return n1;
    }
};

int main()
{
    io;
    Solution s;
    // vector<int> nums1 = {2, 7, 11, 15};
    // vector<int> nums2 = {1, 10, 4, 11};
    vector<int> nums1 = {12, 24, 8, 32};
    vector<int> nums2 = {13, 25, 32, 11};
    vector<int> v = s.advantageCount(nums1, nums2);
    for (int n : v)
        cout << n << ' ';
    cout << endl;
    return 0;
}