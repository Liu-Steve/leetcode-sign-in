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
    vi countPairs(int n, vv &edges, vi &queries)
    {
        vi deg(n + 1); // 度数
        memory e_cnt;  // 边出现次数
        for (auto &e : edges)
        {
            if (e[0] > e[1])
                swap(e[0], e[1]);
            deg[e[0]]++;
            deg[e[1]]++;
            e_cnt[(e[0] << 16) | e[1]]++;
        }

        memory d_cnt; // 度数出现次数
        for (int i = 1; i <= n; ++i)
            d_cnt[deg[i]]++;

        int k = *max_element(deg.begin() + 1, deg.end()) * 2 + 2;
        vi cnts(k); // cnt == i 的答案
        for (auto [d1, c1] : d_cnt)
            for (auto [d2, c2] : d_cnt)
                if (d1 < d2)
                    cnts[d1 + d2] += c1 * c2;
                else if (d1 == d2)
                    cnts[d1 + d2] += c1 * (c1 - 1) / 2;
        
        for (auto [e, c] : e_cnt)
        {
            int s = deg[e >> 16] + deg[e & 0xffff];
            cnts[s]--;
            cnts[s - c]++;
        }

        for (int i = k - 1; i > 0; --i)
            cnts[i - 1] += cnts[i];

        for (int &q : queries)
            q = cnts[min(q + 1, k - 1)];

        return queries;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
