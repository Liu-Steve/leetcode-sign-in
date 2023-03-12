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
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
        // build map
        vector<int> tree[n];
        for (auto &e : edges)
        {
            tree[e[0] - 1].emplace_back(e[1] - 1);
            tree[e[1] - 1].emplace_back(e[0] - 1);
        }

        // find distance
        vector<vector<int>> dis(n, vector<int>(n));
        function<void(int, int, int)> cnt_dis = [&](int p1, int p2, int fa)
        {
            for (int sub : tree[p2])
                if (sub != fa)
                {
                    dis[p1][sub] = dis[p1][p2] + 1;
                    cnt_dis(p1, sub, p2);
                }
        };
        for (int i = 0; i < n; ++i)
            cnt_dis(i, i, -1);

        // enu
        function<int(int, int, int, int, int)> enu = [&](int p1, int p2, int mx, int x, int fa) 
        {
            int cnt = 1;
            for (int sub : tree[x])
                if (sub != fa && 
                (dis[p1][sub] < mx || dis[p1][sub] == mx && sub > p2) && // sub > p2 not sub > p1
                (dis[p2][sub] < mx || dis[p2][sub] == mx && sub > p1))
                    cnt *= enu(p1, p2, mx, sub, x);
            if (dis[p1][x] + dis[p2][x] > mx)
                ++cnt;
            return cnt;
        };

        vector<int> ans(n - 1);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ans[dis[i][j] - 1] += enu(i, j, dis[i][j], i, -1);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}