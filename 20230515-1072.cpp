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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        typedef bitset<305> i_300;
        unordered_map<i_300, int> mp;
        for (auto &m : matrix)
        {
            i_300 n = 0;
            for (int i = 0; i < m.size(); ++i)
                n.set(i, m[i] ^ m[0]);
            mp[n]++;
        }
        int ans = 1;
        for (auto &[k, v] : mp)
            ans = max(ans, v);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
