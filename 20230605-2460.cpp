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
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int p = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] == 0)
                continue;
            if (nums[i] == nums[i + 1])
            {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
            ans[p] = nums[i];
            p++;
        }
        ans[p] = nums[n - 1];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
