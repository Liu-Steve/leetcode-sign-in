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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int p = 0; p < n - 2;)
        {
            if (nums[p] > 0)
                break;
            int l = p + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[p] + nums[l] + nums[r];
                if (sum < 0)
                {
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                }
                else if (sum > 0)
                {
                    r--;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else
                {
                    ans.emplace_back(vector<int>{nums[p], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
            p++;
            while (p < n - 2 && nums[p] == nums[p - 1])
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
