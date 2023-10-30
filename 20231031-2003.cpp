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
    vi smallestMissingValueSubtree(vi &parents, vi &nums)
    {
        int n = parents.size();
        vi ans(n, 1);

        // find 1 gene
        int node = -1;
        for (int i = 0; i < n; ++i)
            if (nums[i] == 1)
            {
                node = i;
                break;
            }
        if (node == -1)
            return ans;

        // build tree
        vv children(n);
        for (int i = 1; i < n; ++i)
            children[parents[i]].emplace_back(i);

        // dfs count subtree gene
        vb vis(n, false);
        hm gene;
        function<void(int)> dfs = [&](int now) {
            if (vis[now])
                return;
            vis[now] = true;
            gene.emplace(nums[now]);
            for (int c : children[now])
                dfs(c);
        };

        // find answer
        int val = 2;
        while (node != -1)
        {
            dfs(node);
            while(gene.count(val))
                val++;
            ans[node] = val;
            node = parents[node];
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
