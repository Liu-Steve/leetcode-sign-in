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

class MyQueue
{
private:
    stack<int> st1, st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st2.push(x);
    }

    int pop()
    {
        if (st1.empty())
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        int ans = st1.top();
        st1.pop();
        return ans;
    }

    int peek()
    {
        if (st1.empty())
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        return st1.top();
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};

int main()
{
    io;
    return 0;
}
