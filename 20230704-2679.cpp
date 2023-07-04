#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
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
    int matrixSum(vector<vector<int>>& nums) {
        for (auto & num: nums)
            sort(num.begin(), num.end());
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            int mx = nums[0][i];
            for (int j = 1; j < n; ++j)
                mx = max(mx, nums[j][i]);
            ans += mx;
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
