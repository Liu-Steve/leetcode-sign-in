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
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> cnt(n, 0);
        vector<vector<int>> nxt(n);
        vector<int> etime(n, 0);
        for (auto &r : relations)
        {
            nxt[r[0] - 1].emplace_back(r[1] - 1);
            cnt[r[1] - 1]++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0)
                pq.emplace(0, i);
        int ans = 0;
        while (!pq.empty())
        {
            auto [t, p] = pq.top();
            pq.pop();
            t += time[p];
            ans = max(ans, t);
            for (int np : nxt[p])
            {
                cnt[np]--;
                etime[np] = max(etime[np], t);
                if (cnt[np] == 0)
                    pq.emplace(etime[np], np);
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
