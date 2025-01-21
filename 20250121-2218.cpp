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
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        vector<vector<int>> pre;
        for (auto &p : piles)
        {
            pre.push_back({0});
            for (int num : p)
                pre.back().push_back(pre.back().back() + num);
        }
        unordered_map<long long, int> mp;
        auto h = [](long long i, long long k) -> long long
        {
            return (i << 32) | k;
        };
        auto dfs = [&](auto &&dfs, int i, int k) -> int
        {
            if (mp.count(h(i, k)))
                return mp[h(i, k)];
            if (i == 0)
            {
                if (k > piles[i].size())
                    return -1;
                mp[h(0, k)] = pre[0][k];
                return pre[0][k];
            }
            int ans = -1;
            for (int j = 0; j < pre[i].size(); ++j)
            {
                int child = dfs(dfs, i - 1, k - j);
                if (child != -1)
                    ans = max(ans, child + pre[i][j]);
            }
            mp[h(i, k)] = ans;
            return ans;
        };
        return dfs(dfs, piles.size() - 1, k);
    }
};

int main()
{
    io;

    Solution s;
    vector<vector<int>> p{{1, 100, 3}, {7, 8, 9}};
    cout << s.maxValueOfCoins(p, 2) << endl;

    return 0;
}
