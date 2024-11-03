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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();
        vector<vector<int>> con;
        for (auto &s : special)
        {
            int rawPrice = 0;
            for (int i = 0; i < n; ++i)
                rawPrice += price[i] * s[i];
            if (rawPrice > s[n])
                con.emplace_back(s);
        }
        swap(special, con);
        auto hash = [&](vector<int> &target) -> int
        {
            int ret = 0;
            for (int t : target)
            {
                ret *= 11;
                ret += t;
            }
            return ret;
        };
        unordered_map<int, int> mem;
        auto dfs = [&](auto &&dfs, vector<int> &target) -> int
        {
            int h = hash(target);
            if (mem.count(h))
                return mem[h];
            int ans = 0;
            for (int i = 0; i < n; ++i)
                ans += price[i] * target[i];
            for (auto &s : special)
            {
                vector<int> newTarget(target);
                bool valid = true;
                for (int i = 0; i < n; ++i)
                {
                    newTarget[i] -= s[i];
                    if (newTarget[i] < 0)
                    {
                        valid = false;
                        break;
                    }
                }
                if (!valid)
                    continue;
                ans = min(ans, dfs(dfs, newTarget) + s[n]);
            }
            mem[h] = ans;
            return ans;
        };
        return dfs(dfs, needs);
    }
};

int main()
{
    io;
    return 0;
}
