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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int maxScoreWords(vs &w, vc &l, vi &s)
    {
        int ans = 0;
        int left[26];
        int val[w.size()];
        memset(left, 0, sizeof(left));
        for (char ch : l)
            ++left[ch - 'a'];
        for (int i = 0; i < w.size(); ++i)
        {
            val[i] = 0;
            for (char ch : w[i])
                val[i] += s[ch - 'a'];
        }

        function<void(int, int)> dfs = [&](int i, int total)
        {
            if (i < 0)
            {
                ans = max(ans, total);
                return;
            }
            dfs(i - 1, total);
            int len = w[i].size();
            for (int j = 0; j < len; ++j)
            {
                --left[w[i][j] - 'a'];
                if (left[w[i][j] - 'a'] < 0)
                {
                    len = j;
                    break;
                }
            }
            if (len == w[i].size())
            {
                dfs(i - 1, total + val[i]);
                len--;
            }
            for (int j = 0; j <= len; ++j)
                ++left[w[i][j] - 'a'];
        };

        dfs(w.size() - 1, 0);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"dog", "cat", "dad", "good"};
    vc v2 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vi v3 = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << s.maxScoreWords(v1, v2, v3) << endl;
    return 0;
}