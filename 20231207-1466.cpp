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
    int minReorder(int n, vv &connections)
    {
        vv nxt(n);
        vv rnxt(n);
        for (vi c : connections)
        {
            nxt[c[0]].emplace_back(c[1]);
            rnxt[c[1]].emplace_back(c[0]);
        }
        vb vis(n, false);

        int ans = 0;
        function<void(int)> dfs = [&](int root)
        {
            vis[root] = true;
            for (int c : nxt[root])
            {
                if (vis[c])
                    continue;
                ans++;
                dfs(c);
            }
            for (int c : rnxt[root])
            {
                if (vis[c])
                    continue;
                dfs(c);
            }
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
