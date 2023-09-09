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
    vector<int> findOrder(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> nxt(n);
        vector<int> cnt(n);
        for (auto &p : pre)
        {
            nxt[p[1]].emplace_back(p[0]);
            cnt[p[0]]++;
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
            }
        if (z.size() != n)
            return vector<int>{};
        return z;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
