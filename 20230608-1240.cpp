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
    int tilingRectangle(int n, int m)
    {
        vector<vector<bool>> rect(n, vector<bool>(m, false));
        int ans = max(n, m);
        int filled = 0;

        auto clc = [&](int x, int y, int k)
        {
            for (int i = x; i < x + k; ++i)
                for (int j = y; j < y + k; ++j)
                    rect[i][j] = false;
            filled -= k * k;
        };

        auto fill = [&](int x, int y, int k)
        {
            for (int i = 0; i < k; ++i)
                if (rect[x + i][y + k - 1] || rect[x + k - 1][y + i])
                    return false;
            for (int i = 0; i < k; ++i)
            {
                rect[x + i][y + k - 1] = true;
                rect[x + k - 1][y + i] = true;
            }
            filled += 2 * k - 1;
            return true;
        };

        // vector<tuple<int, int, int>> st;

        function<void(int, int, int)> dfs = [&, n, m](int x, int y, int cnt)
        {
            if (cnt >= ans)
            {
                // st.pop_back();
                return;
            }
            while (rect[x][y])
            {
                y++;
                if (y >= m)
                {
                    x++;
                    y = 0;
                }
                if (x >= n)
                {
                    cout << "err" << endl;
                    // st.pop_back();
                    return;
                }
            }
            int k = 1;
            for (; k <= min(n - x, m - y); ++k)
            {
                bool succ = fill(x, y, k);
                if (!succ)
                    break;
                // st.emplace_back(x, y, k);
                if (filled == m * n)
                {
                    ans = cnt;
                    // cout << cnt << endl;
                    // for (auto t : st)
                    //     cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
                    // st.pop_back();
                    clc(x, y, k);
                    return;
                }
                dfs(x, y + k - 1, cnt + 1);
            }
            clc(x, y, k - 1);
            // st.pop_back();
        };

        dfs(0, 0, 1);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.tilingRectangle(2, 3) << endl;
    cout << s.tilingRectangle(5, 8) << endl;
    cout << s.tilingRectangle(11, 13) << endl;
    cout << s.tilingRectangle(13, 11) << endl;
    return 0;
}
