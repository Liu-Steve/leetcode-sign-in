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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
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

int main()
{
    io;
    Solution s;
    return 0;
}
