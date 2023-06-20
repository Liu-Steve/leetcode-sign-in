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
private:
    int n;
    int m;
    stack<pair<int, int>> st;
    const vector<int> bias = {1, 1, 0, -1, -1, 0, 1, -1, 1};
    int putX(vector<vector<int>> &b)
    {
        auto [x, y] = st.top();
        st.pop();
        int ret = 0;
        for (int i = 0; i < 8; ++i)
        {
            int px = x + bias[i];
            int py = y + bias[i + 1];
            int add = 0;
            while (px >= 0 && px < n && py >= 0 && py < m && b[px][py] != 0)
            {
                if (b[px][py] == -1)
                {
                    st.emplace(px, py);
                    add++;
                    b[px][py] = 1;
                }
                else
                {
                    ret += add;
                    add = 0;
                }
                px += bias[i];
                py += bias[i + 1];
            }
            while (add--)
            {
                auto [px, py] = st.top();
                b[px][py] = -1;
                st.pop();
            }
        }
        return ret;
    }

public:
    int flipChess(vector<string> &chessboard)
    {
        n = chessboard.size();
        m = chessboard[0].size();
        vector<vector<int>> b(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (chessboard[i][j] != '.')
                    b[i][j] = (chessboard[i][j] == 'X' ? 1 : -1);

        int ret = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (b[i][j] != 0)
                    continue;
                auto nb = vector<vector<int>>(b);
                nb[i][j] = 1;
                st.emplace(i, j);
                int ans = 0;
                while (!st.empty())
                    ans += putX(nb);
                ret = max(ret, ans);
            }

        return ret;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"....X.", "....X.", "XOOO..", "......", "......"};
    cout << s.flipChess(v1) << endl;
    return 0;
}
