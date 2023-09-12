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
    vb checkIfPrerequisite(int n, vv &pre, vv &q)
    {
        vv nxt(n);
        vi cnt(n);
        vector<hm> bh(n);
        for (auto &p : pre)
        {
            nxt[p[0]].emplace_back(p[1]);
            cnt[p[1]]++;
            bh[p[1]].emplace(p[0]);
        }
        vector<int> z;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0)
                z.emplace_back(i);
        for (int i = 0; i < z.size(); ++i)
            for (int x : nxt[z[i]])
            {
                cnt[x]--;
                if (cnt[x] == 0)
                    z.emplace_back(x);
                for (int node : bh[z[i]])
                    bh[x].emplace(node);
            }
        vb ans;
        for (auto &qq : q)
            ans.emplace_back(bh[qq[1]].count(qq[0]));
        return ans;
    }
};

int main()
{
    io;
    Solution s;

    vv p1 = {{1, 2}, {1, 0}, {2, 0}};
    vv q1 = {{1, 0}, {1, 2}};
    auto a1 = s.checkIfPrerequisite(3, p1, q1);

    return 0;
}
