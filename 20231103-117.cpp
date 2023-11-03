#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *r)
    {
        Node *root = r;
        while (root)
        {
            Node *nxt_root = nullptr;
            Node pre; // 每层节点前引入的节点
            Node *p = &pre;
            for (Node *fp = root; fp; fp = fp->next) // 遍历每层节点
                for (Node *child : {fp->left, fp->right})
                {
                    if (child)
                    {
                        if (!nxt_root)
                            nxt_root = child;
                        p = p->next = child; // 连接子节点的下一个节点}
                    }
                    root = nxt_root; // 去下一层
                }
        }
        return r;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
