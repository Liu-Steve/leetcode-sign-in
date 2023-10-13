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

// class Solution
// {
// public:
//     vi avoidFlood(vi &rains)
//     {
//         hm cnt;
//         int can_dry = 0;
//         vi dry;
//         for (int r : rains)
//         {
//             if (r == 0)
//             {
//                 can_dry++;
//                 continue;
//             }
//             if (cnt.count(r))
//             {
//                 dry.emplace_back(r);
//                 if (dry.size() > can_dry)
//                     return vi{};
//             }
//             cnt.emplace(r);
//         }
//         vi ans;
//         int p = 0;
//         for (int r : rains)
//         {
//             if (r != 0)
//             {
//                 ans.emplace_back(-1);
//                 continue;
//             }
//             if (p < dry.size())
//             {
//                 ans.emplace_back(dry[p]);
//                 p++;
//                 continue;
//             }
//             ans.emplace_back(1);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> dry;
        unordered_map<int, int> pool;
        for (int i = 0; i < n; ++i)
        {
            if (rains[i] == 0)
            {
                dry.emplace(i);
                continue;
            }
            ans[i] = -1;
            if (pool.count(rains[i]))
            {
                auto it = dry.lower_bound(pool[rains[i]]);
                if (it == dry.end())
                    return vector<int>{};
                ans[*it] = rains[i];
                dry.erase(it);
            }
            pool[rains[i]] = i;
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
