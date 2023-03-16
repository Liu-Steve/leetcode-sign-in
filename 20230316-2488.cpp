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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        int pos = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] == k)
            {
                pos = i;
                break;
            }
        int mp[2 * n];
        memset(mp, 0, sizeof(mp));
        mp[n] = 1;
        int x = n;
        for (int i = pos - 1; i >= 0; --i)
        {
            x += nums[i] < k ? 1 : -1;
            mp[x]++;
        }
        x = n;
        int ans = mp[n] + mp[n - 1];
        for (int i = pos + 1; i < n; ++i)
        {
            x += nums[i] < k ? -1 : 1;
            ans += mp[x] + mp[x - 1];
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