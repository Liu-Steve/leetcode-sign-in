#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        int idx1 = 0, idx2 = k, idx3 = 2 * k;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxSum123 = 0;
        while (idx3 < n)
        {
            sum1 += nums[idx1];
            sum2 += nums[idx2];
            sum3 += nums[idx3];
            idx1++;
            idx2++;
            idx3++;
            if (idx1 < k)
                continue;
            if (sum1 > maxSum1) {
                maxSum1 = sum1;
                maxSum1Idx = idx1 - k;
            }
            if (maxSum1 + sum2 > maxSum12) {
                maxSum12 = maxSum1 + sum2;
                maxSum12Idx1 = maxSum1Idx;
                maxSum12Idx2 = idx2 - k;
            }
            if (maxSum12 + sum3 > maxSum123) {
                maxSum123 = maxSum12 + sum3;
                ans = {maxSum12Idx1, maxSum12Idx2, idx3 - k};
            }
            sum1 -= nums[idx1 - k];
            sum2 -= nums[idx2 - k];
            sum3 -= nums[idx3 - k];
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
