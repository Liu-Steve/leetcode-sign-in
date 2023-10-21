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
    ll countPairs(ll n, vv &edges)
    {
        vv nxt(n);
        for (auto &e : edges)
        {
            nxt[e[0]].emplace_back(e[1]);
            nxt[e[1]].emplace_back(e[0]);
        }
        vb vis(n);
        ll ans = 0;
        function<int(int)> dfs = [&](int pos){
            if (vis[pos])
                return 0;
            vis[pos] = true;
            int cnt = 1;
            for (int npos : nxt[pos])
                cnt += dfs(npos);
            return cnt;
        };
        for (int i = 0; i < n; ++i)
        {
            ll cnt = dfs(i);
            ans += cnt * (cnt - 1) / 2;
        }
        ans = n * (n - 1) / 2 - ans;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
