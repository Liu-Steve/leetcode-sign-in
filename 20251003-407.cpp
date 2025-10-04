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
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        vector visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    pq.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
        int res = 0;
        vector<int> dirs{-1, 0, 1, 0, -1};
        while (!pq.empty())
        {
            pr curr = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k)
            {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny])
                {
                    if (heightMap[nx][ny] < curr.first)
                        res += curr.first - heightMap[nx][ny];
                    visit[nx][ny] = true;
                    pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }
        return res;
    }
};

int main()
{
    io;
    return 0;
}
