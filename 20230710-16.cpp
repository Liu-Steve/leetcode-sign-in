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

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        for (int p = 0; p < n - 2;)
        {
            if (p > 0 && nums[p] == nums[p - 1])
                continue; // speed up
            int l = p + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[p] + nums[l] + nums[r];
                ans = abs(ans - target) > abs(sum - target) ? sum : ans;
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                    return target;
            }
            p++;
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
