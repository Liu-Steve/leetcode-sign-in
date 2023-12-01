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

class Solution
{
public:
    int firstCompleteIndex(vi &arr, vv &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vi x(m * n), y(m * n), cx(m, n), cy(n, m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int idx = mat[i][j] - 1;
                x[idx] = i;
                y[idx] = j;
            }
        int i = 0;
        for (; i < n * m; ++i)
        {
            int color = arr[i] - 1;
            --cx[x[color]];
            --cy[y[color]];
            if (cx[x[color]] && cy[y[color]])
                continue;
            return i;
        }
        return i;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
