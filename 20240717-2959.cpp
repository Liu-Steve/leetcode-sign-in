#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        int NON = 1e6;
        vector<vector<int>> dis(n, vector<int>(n, NON));
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (auto &r : roads)
        {
            dis[r[0]][r[1]] = min(dis[r[0]][r[1]], r[2]);
            dis[r[1]][r[0]] = min(dis[r[1]][r[0]], r[2]);
        }
        int ans = 0;
        for (int msk = 0; msk < (1 << n); ++msk)
        {
            vector<int> idx;
            for (int i = 0; i < n; ++i)
                if (msk & (1 << i))
                    idx.push_back(i);
            int m = idx.size();
            vector<vector<int>> f(m, vector<int>(m, NON));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < m; ++j)
                    f[i][j] = dis[idx[i]][idx[j]];
            for (int x = 0; x < m; ++x)
                for (int i = 0; i < m; ++i)
                    for (int j = 0; j < m; ++j)
                        f[i][j] = min(f[i][j], f[i][x] + f[x][j]);
            int far = 0;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < m; ++j)
                    far = max(far, f[i][j]);
            if (far <= maxDistance)
                ans++;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
