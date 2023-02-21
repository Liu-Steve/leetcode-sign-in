#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int s = 0, n = piles.size(), f[n][n + 1];
        for (int i = n - 1; i >= 0; --i)
        {
            s += piles[i];
            for (int m = 1; m <= i / 2 + 1; ++m)
            {
                if (i + m * 2 >= n)
                    f[i][m] = s;
                else
                {
                    int mn = INT_MAX;
                    for (int x = 1; x <= m * 2; ++x)
                        mn = min(mn, f[i + x][max(m, x)]);
                    f[i][m] = s - mn;
                }
            }
        }
        return f[0][1];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {2, 7, 9, 4, 4}; // 10
    cout << s.stoneGameII(v1) << endl;
    vi v2 = {1, 2, 3, 4, 5, 100}; // 104
    cout << s.stoneGameII(v2) << endl;
    vi v3 = {1}; // 1
    cout << s.stoneGameII(v3) << endl;
    vi v4 = {1, 1, 1}; // 2
    cout << s.stoneGameII(v4) << endl;
    vi v5 = {13, 456, 19, 326, 326, 19, 47, 13, 443, 284, 57}; // 1136
    cout << s.stoneGameII(v5) << endl;
    vi v6 = {1, 100, 100, 1, 1, 1, 100, 100}; // 204
    cout << s.stoneGameII(v6) << endl;
    return 0;
}