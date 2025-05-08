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
#define MAX_N 10000
#define MAX_E 13

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
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<int> b{0, 1, 0, -1, 0};
        typedef tuple<int, int, int> ele;
        priority_queue<ele, vector<ele>, greater<ele>> pq;
        vector ans(n, vector<int>(m, INT32_MAX));
        pq.emplace(0, 0, 0);
        while (!pq.empty())
        {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (ans[x][y] <= t)
                continue;
            ans[x][y] = t;
            for (int i = 0; i < 4; ++i)
            {
                int bx = x + b[i];
                int by = y + b[i + 1];
                if (bx < 0 || bx >= n || by < 0 || by >= m)
                    continue;
                int bt = max(t, moveTime[bx][by]) + 1 + (x + y) % 2;
                if (bt >= ans[bx][by])
                    continue;
                pq.emplace(bt, bx, by);
            }
        }
        return ans[n - 1][m - 1];
    }
};

int main()
{
    io;
    return 0;
}
