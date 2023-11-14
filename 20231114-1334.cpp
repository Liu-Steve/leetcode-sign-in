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
    int findTheCity(int n, vv &edges, int dt)
    {
        int inf = 0x3f3f3f3f;
        vv dis(n, vi(n, inf));
        for (auto &e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int ans = 0;
        int cnt = n + 1;
        for (int i = 0; i < n; ++i)
        {
            int c = 0;
            for (int j = 0; j < n; ++j)
            {
                if (dis[i][j] <= dt)
                    c++;
            }
            if (c <= cnt)
            {
                ans = i;
                cnt = c;
            }
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
