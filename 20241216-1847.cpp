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
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        int n = rooms.size();
        int k = queries.size();
        vector<int> ans(k);
        sort(rooms.begin(), rooms.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        for (int i = 0; i < k; ++i)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        set<int> id;
        int p = 0;
        for (auto &q : queries)
        {
            while (p < n && rooms[p][1] >= q[1])
            {
                id.emplace(rooms[p][0]);
                p++;
            }
            if (id.empty())
            {
                ans[q[2]] = -1;
                continue;
            }
            auto it = id.lower_bound(q[0]);
            if (it == id.begin())
                ans[q[2]] = *it;
            else if (it == id.end())
                ans[q[2]] = *(--it);
            else
            {
                int id_r = *it;
                int id_l = *(--it);
                if (abs(id_l - q[0]) <= abs(id_r - q[0]))
                    ans[q[2]] = id_l;
                else
                    ans[q[2]] = id_r;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
