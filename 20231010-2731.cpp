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
    int sumDistance(vi &nums, string s, int d)
    {
        int n = nums.size();
        vl pos;
        pos.assign(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'L')
                pos[i] -= d;
            else
                pos[i] += d;
        }
        sort(pos.begin(), pos.end());
        ll lst = pos[0];
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ll add = (pos[i] - lst) * i;
            add %= MOD;
            add *= n - i;
            add %= MOD;
            ans += add;
            ans %= MOD;
            lst = pos[i];
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
