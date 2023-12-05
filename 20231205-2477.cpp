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
    ll minimumFuelCost(vv &roads, int seats)
    {
        int n = roads.size() + 1;
        vv nxt(n);
        for (vi &r : roads)
        {
            nxt[r[0]].push_back(r[1]);
            nxt[r[1]].push_back(r[0]);
        }
        vb vis(n, false);
        ll ans = 0;

        function<int(int)> dfs = [&](int root)
        {
            if (vis[root])
                return 0;
            vis[root] = true;
            int ret = 1;
            for (int sub : nxt[root])
                ret += dfs(sub);
            if (root != 0)
                ans += (ret / seats) + (ret % seats != 0);
            return ret;
        };

        dfs(0);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
