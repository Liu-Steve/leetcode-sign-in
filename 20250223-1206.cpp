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

class Skiplist
{
public:
    static const int level = 8;

    struct Node
    {
        int val;
        vector<Node *> next;

        Node(int _val) : val(_val)
        {
            next.resize(level, NULL);
        }
    } *head;

    Skiplist()
    {
        head = new Node(-1);
    }

    ~Skiplist()
    {
        delete head;
    }

    void find(int target, vector<Node *> &pre)
    {
        auto p = head;
        for (int i = level - 1; i >= 0; i--)
        {
            while (p->next[i] && p->next[i]->val < target)
                p = p->next[i];
            pre[i] = p;
        }
    }

    bool search(int target)
    {
        vector<Node *> pre(level);
        find(target, pre);

        auto p = pre[0]->next[0];
        return p && p->val == target;
    }

    void add(int num)
    {
        vector<Node *> pre(level);
        find(num, pre);

        auto p = new Node(num);
        for (int i = 0; i < level; i++)
        {
            p->next[i] = pre[i]->next[i];
            pre[i]->next[i] = p;
            if (rand() % 2)
                break;
        }
    }

    bool erase(int num)
    {
        vector<Node *> pre(level);
        find(num, pre);

        auto p = pre[0]->next[0];
        if (!p || p->val != num)
            return false;
        for (int i = 0; i < level && pre[i]->next[i] == p; i++)
            pre[i]->next[i] = p->next[i];
        delete p;
        return true;
    }
};

int main()
{
    io;
    return 0;
}
