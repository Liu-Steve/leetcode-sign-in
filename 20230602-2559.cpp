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
    vi vowelStrings(vs &words, vv &queries)
    {
        vi pre = {0};
        vb m = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
        for (auto &s : words)
            pre.emplace_back((m[s.front() - 'a'] && m[s.back() - 'a']) + pre.back());
        vi ans;
        for (auto q : queries)
            ans.emplace_back(pre[q[1] + 1] - pre[q[0]]);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
