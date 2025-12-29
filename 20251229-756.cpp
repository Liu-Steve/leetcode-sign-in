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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
typedef unordered_map<ll, int> memory;

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<int, vector<char>> mp;
        for (auto &a : allowed)
            mp[((int)a[0] << 8) | a[1]].push_back(a[2]);
        int len = bottom.size();
        vector<string> tower(len, bottom);
        auto dfs = [&](auto &&dfs, int x, int y) -> bool
        {
            if (x == len - 1)
                return true;
            if (x + y == len - 1)
                return dfs(dfs, x + 1, 0);
            auto &ch = mp[((int)tower[x][y] << 8) | tower[x][y + 1]];
            for (char c : ch)
            {
                tower[x + 1][y] = c;
                if (dfs(dfs, x, y + 1))
                    return true;
            }
            return false;
        };
        return dfs(dfs, 0, 0);
    }
};

int main()
{
    io;
    return 0;
}
