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
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> pre(1, 0);
        int n = nums.size();
        for (int num : nums)
            pre.emplace_back(pre.back() + num);
        int ans = 0;
        unordered_map<int, int> hm;
        hm[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int want = pre[i] - k;
            if (hm.find(want) != hm.end())
                ans += hm[want];
            hm[pre[i]]++;
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
