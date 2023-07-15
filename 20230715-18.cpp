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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int a = 0; a < n - 3;)
        {
            if (nums[a] * 4ll > target)
                break;
            for (int p = a + 1; p < n - 2;)
            {
                if (nums[a] + nums[p] * 3ll > target)
                    break;
                int l = p + 1;
                int r = n - 1;
                while (l < r)
                {
                    long long sum = 0ll + nums[a] + nums[p] + nums[l] + nums[r];
                    if (sum < target)
                    {
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                    }
                    else if (sum > target)
                    {
                        r--;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                    else
                    {
                        ans.emplace_back(vector<int>{nums[a], nums[p], nums[l], nums[r]});
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
            a++;
            while (a < n - 3 && nums[a] == nums[a - 1])
                a++;
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
