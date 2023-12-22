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
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> g;
        vector<int> suf(n);
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            auto it = lower_bound(g.begin(), g.end(), num);
            suf[i] = it - g.begin() + 1;
            if (it == g.end())
                g.push_back(num);
            else
                *it = num;
        }
        g.clear();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int num = nums[i];
            auto it = lower_bound(g.begin(), g.end(), num);
            int pre = it - g.begin() + 1;
            if (it == g.end())
                g.push_back(num);
            else
                *it = num;
            if (pre >= 2 && suf[i] >= 2)
                ans = max(ans, pre + suf[i] - 1);
        }
        return n - ans;
    }
};

int main()
{
    io;
    return 0;
}
