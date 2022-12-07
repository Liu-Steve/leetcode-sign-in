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
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int num : nums1)
            sum1 += num;
        for (int num : nums2)
            sum2 += num;
        if (sum1 > sum2)
        {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        else if (sum1 == sum2)
            return 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int szs = sz1 + sz2;
        if (sz1 * 6 < sz2)
            return -1;
        for (int i = 0; i < sz1; ++i)
            nums1[i] = 7 - nums1[i];
        int sumd = sum2 - sum1;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < szs; ++i)
        {
            sum += nums1[i] - 1;
            if (sum >= sumd)
                return i + 1;
        }
        return szs + 1;
    }
};

int main()
{
    io;
    Solution s;
    vi v11 = {1, 2, 3, 4, 5, 6};
    vi v12 = {1, 1, 2, 2, 2, 2};
    cout << s.minOperations(v11, v12) << endl;
    vi v21 = {1, 1, 1, 1, 1, 1, 1};
    vi v22 = {6};
    cout << s.minOperations(v21, v22) << endl;
    vi v31 = {6, 6};
    vi v32 = {1};
    cout << s.minOperations(v31, v32) << endl;
    return 0;
}