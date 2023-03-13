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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    vv restoreMatrix(vi& rowSum, vi& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vv ans(n, vector(m, 0));
        priority_queue<pr, vp, greater<pr>> rowH;
        priority_queue<pr, vp, greater<pr>> colH;
        for (int i = 0; i < n; ++i)
            rowH.emplace(rowSum[i], i);
        for (int i = 0; i < m; ++i)
            colH.emplace(colSum[i], i);
        while (!rowH.empty() && !colH.empty())
        {
            auto [rval, ridx] = rowH.top();
            auto [cval, cidx] = colH.top();
            rowH.pop();
            colH.pop();
            if (rval < cval)
            {
                ans[ridx][cidx] = rval;
                colH.emplace(cval - rval, cidx);
            }
            else if (rval > cval)
            {
                ans[ridx][cidx] = cval;
                rowH.emplace(rval - cval, ridx);
            }
            else
                ans[ridx][cidx] = rval;
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