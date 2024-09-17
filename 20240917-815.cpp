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
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; i++)
        {
            for (int site : routes[i])
            {
                for (int j : rec[site])
                    edge[i][j] = edge[j][i] = true;
                rec[site].push_back(i);
            }
        }
        vector<int> dis(n, -1);
        queue<int> que;
        for (int bus : rec[source])
        {
            dis[bus] = 1;
            que.push(bus);
        }
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            for (int y = 0; y < n; y++)
            {
                if (edge[x][y] && dis[y] == -1)
                {
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }
        int ret = INT_MAX;
        for (int bus : rec[target])
            if (dis[bus] != -1)
                ret = min(ret, dis[bus]);
        return ret == INT_MAX ? -1 : ret;
    }
};

int main()
{
    io;
    return 0;
}
