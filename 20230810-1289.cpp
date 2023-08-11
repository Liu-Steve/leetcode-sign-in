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

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int v1 = 0, v2 = 0, pos = -1;
        for (auto &ln : grid)
        {
            int nv1 = INT32_MAX, nv2 = INT32_MAX, npos = -1;
            for (int i = 0; i < n; ++i)
            {
                int val = ln[i] + (pos != i ? v1 : v2);
                if (val < nv1)
                {
                    nv2 = nv1;
                    nv1 = val;
                    npos = i;
                }
                else if (val < nv2)
                    nv2 = val;
            }
            v1 = nv1;
            v2 = nv2;
            pos = npos;
        }
        return v1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
