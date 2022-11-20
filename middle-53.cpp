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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        // 做前缀和
        for (int i = 1; i < len; ++i) {
            nums[i] += nums[i - 1];
        }
        int res = nums[0];
        int mi = min(nums[0], 0);
        for (int i = 1; i < len; ++i) {
            int sum = nums[i] - mi;
            if (sum > res) {
                res = sum;
            }
            if (nums[i] < mi) {
                mi = nums[i];
            }
        }
        return res;
    }
};

int main() {
    io;
    Solution s;
    vi v1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v1) << endl;
    vi v2 = {1};
    cout << s.maxSubArray(v2) << endl;
    vi v3 = {5,4,-1,7,8};
    cout << s.maxSubArray(v3) << endl;
    return 0;
}