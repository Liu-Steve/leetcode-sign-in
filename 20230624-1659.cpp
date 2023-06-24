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
    int getMaxGridHappiness(int m, int n, int ic, int ec)
    {
        int full = pow(3, m);
        vector<vector<vv>> mem(m * n, vector<vv>(full, vv(ic + 1, vi(ec + 1, -1))));
        int score[3][3] = {
            {0, 0, 0},
            {0, -60, -10},
            {0, -10, 40}};

        function<int(int, int, int, int)> dfs = [&](int pos, int msk, int in, int ex)
        {
            if (pos == m * n || (in == 0 && ex == 0))
                return 0;
            int &res = mem[pos][msk][in][ex];
            if (res != -1)
                return res;
            int up = msk / (full / 3);
            int left = (pos % m == 0) ? 0 : (msk % 3);
            for (int i = 0; i < 3; ++i)
            {
                if ((i == 1 && in == 0) || (i == 2 && ex == 0))
                    continue;
                int newMsk = (msk * 3 + i) % full;
                int ans = dfs(pos + 1, newMsk, in - (i == 1), ex - (i == 2));
                ans += score[up][i] + score[left][i];
                ans += (i == 1 ? 120 : (i == 2 ? 40 : 0));
                res = max(res, ans);
            }
            return res;
        };

        return dfs(0, 0, ic, ec);
    }
};

int main()
{
    io;
    Solution s;
    cout << s.getMaxGridHappiness(3, 1, 2, 1) << endl;
    return 0;
}
