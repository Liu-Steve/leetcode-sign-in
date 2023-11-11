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
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size() / 2;
        vector<vector<int>> nxt(n);
        for (int i = 0; i < n; ++i)
        {
            int a = row[2 * i] / 2;
            int b = row[2 * i + 1] / 2;
            if (a == b)
                continue;
            nxt[a].emplace_back(b);
            nxt[b].emplace_back(a);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nxt[i].empty())
                continue;
            int now = nxt[i][0];
            int lst = i;
            while (now != i)
            {
                ans++;
                if (nxt[now][0] != lst)
                {
                    lst = now;
                    now = nxt[now][0];
                }
                else
                {
                    lst = now;
                    now = nxt[now][1];
                }
                nxt[lst].clear();
            }
            nxt[i].clear();
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
