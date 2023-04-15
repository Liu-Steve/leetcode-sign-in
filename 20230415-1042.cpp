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
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> nb(n);
        for (vector<int> &p : paths)
        {
            nb[p[0] - 1].emplace_back(p[1] - 1);
            nb[p[1] - 1].emplace_back(p[0] - 1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                bool ok = true;
                for (int k : nb[i])
                    if (j == ans[k])
                    {
                        ok = false;
                        break;
                    }
                if (ok)
                {
                    ans[i] = j;
                    break;
                }
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