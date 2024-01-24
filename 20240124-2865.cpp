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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll maximumSumOfHeights(vi &maxHeights)
    {
        ll n = maxHeights.size();
        vl l(n);
        vl r(n);
        vl stk;
        for (ll i = 0; i < n; ++i)
        {
            while (!stk.empty() && maxHeights[stk.back()] >= maxHeights[i])
                stk.pop_back();
            ll lst = stk.empty() ? -1 : stk.back();
            l[i] = (lst == -1 ? 0 : l[lst]) + maxHeights[i] * (i - lst);
            stk.push_back(i);
        }
        stk.clear();
        for (ll i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() && maxHeights[stk.back()] >= maxHeights[i])
                stk.pop_back();
            ll lst = stk.empty() ? n : stk.back();
            r[i] = (lst == n ? 0 : r[lst]) + maxHeights[i] * (lst - i);
            stk.push_back(i);
        }
        ll ans = 0;
        for (ll i = 0; i < n; ++i)
            ans = max(ans, l[i] + r[i] - maxHeights[i]);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
