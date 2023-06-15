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

// class Solution
// {
// public:
//     vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
//     {
//         vector<vector<int>> pre(1, vector<int>(26));
//         for (char ch : s)
//         {
//             pre.emplace_back(pre.back());
//             pre.back()[ch - 'a']++;
//         }
//         vector<bool> ans;
//         for (auto &q : queries)
//         {
//             int l = q[0];
//             int r = q[1] + 1;
//             int k = q[2];
//             int cnt = 0;
//             for (int i = 0; i < 26; ++i)
//                 cnt += (pre[r][i] - pre[l][i]) & 1;
//             ans.emplace_back(cnt - k * 2 <= ((r - l) & 1));
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        vector<int> pre = {0};
        for (char ch : s)
            pre.emplace_back(pre.back() ^ (1 << (ch - 'a')));
        vector<bool> ans;
        for (auto &q : queries)
        {
            int cnt = 0;
            int x = pre[q[1] + 1] ^ pre[q[0]];
            while (x)
            {
                cnt++;
                x &= x - 1;
            }
            ans.emplace_back(cnt - 2 * q[2] <= ((q[1] - q[0] + 1) & 1));
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv v = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    for (auto a : s.canMakePaliQueries("abcda", v))
        cout << a << ' ';
    cout << endl;
    return 0;
}
