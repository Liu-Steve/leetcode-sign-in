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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<TreeNode *> q1;
        vector<TreeNode *> q2;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        if (root != nullptr)
            q1.push_back(root);
        while (!q1.empty())
        {
            long long sum = 0;
            for (auto p : q1)
            {
                sum += p->val;
                if (p->left != nullptr)
                    q2.push_back(p->left);
                if (p->right != nullptr)
                    q2.push_back(p->right);
            }
            q1.clear();
            swap(q1, q2);
            pq.push(sum);
            if (pq.size() > k)
                pq.pop();
        }
        if (pq.size() == k)
            return pq.top();
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
