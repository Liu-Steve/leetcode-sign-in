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
    int numOfMinutes(int n, int headID, vi &manager, vi &informTime)
    {
        vv peo(n);
        for (int i = 0; i < n; ++i)
            if (manager[i] != -1)
                peo[manager[i]].emplace_back(i);
        
        function<int(int)> dfs = [&](int root){
            if (peo[root].size() == 0)
                return 0;
            int val = informTime[root];
            int ret = val;
            for (int sub: peo[root])
                ret = max(ret, val + dfs(sub));
            return ret;
        };

        return dfs(headID);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
