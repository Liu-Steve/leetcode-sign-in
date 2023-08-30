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
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        if (x == 0)
            return 0;
        auto hash = [](const pair<int, bool>& p){
            return ((long long)(p.first) << 1) | p.second;
        };
        unordered_set<pair<int, bool>, decltype(hash)> vis(6017, hash);
        for (int f : forbidden)
        {
            vis.emplace(f, true);
            vis.emplace(f, false);
        }
        queue<pair<int, bool>> q1;
        queue<pair<int, bool>> q2;
        q1.emplace(0, false);
        vis.emplace(0, false);
        int ans = 1;
        while (!q1.empty())
        {
            while (!q1.empty())
            {
                auto [now, canBack] = q1.front();
                q1.pop();
                if (now + a < 6005 && !vis.count({now + a, true}))
                {
                    if (now + a == x)
                        return ans;
                    q2.emplace(now + a, true);
                    vis.emplace(now + a, true);
                }
                if (now - b >= 0 && canBack && !vis.count({now - b, false}))
                {
                    if (now - b == x)
                        return ans;
                    q2.emplace(now - b, false);
                    vis.emplace(now - b, false);
                }
            }
            ans++;
            swap(q1, q2);
        }
        return -1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
