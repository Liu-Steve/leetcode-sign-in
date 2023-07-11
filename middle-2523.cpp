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
    vector<int> closestPrimes(int left, int right)
    {
        // Euler sieve
        vector<int> pri = {};
        vector<bool> vis(right + 1, true);
        vis[0] = vis[1] = false;
        for (int i = 2; i <= right; ++i)
        {
            if (vis[i])
                pri.emplace_back(i);
            for (long long p : pri)
            {
                if (p * i > right)
                    break;
                vis[i * p] = false;
                if (i % p == 0)
                    break;
            }
        }

        // solve
        int l = lower_bound(pri.begin(), pri.end(), left) - pri.begin();
        if (l + 1 >= pri.size())
            return {-1, -1};
        int p1 = pri[l];
        int p2 = pri[l + 1];
        for (int i = l + 2; i < pri.size(); ++i)
            if (pri[i] - pri[i - 1] < p2 - p1)
            {
                p1 = pri[i - 1];
                p2 = pri[i];
            }
        return {p1, p2};
    }
};

int main()
{
    io;
    Solution s;
    s.closestPrimes(1, 1);
    return 0;
}
