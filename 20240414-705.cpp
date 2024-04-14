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
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

typedef struct st
{
    int val;
    st *nxt;
    st(int v, struct st *n) : val(v), nxt(n) {}
} N;

class MyHashSet
{
private:
    vector<N *> mp;
    static const int M = 31469;

public:
    MyHashSet() : mp(M)
    {
    }

    void add(int key)
    {
        int h = key % M;
        N *ptr = mp[h];
        while (ptr != nullptr)
        {
            if (ptr->val == key)
                return;
            ptr = ptr->nxt;
        }
        N *new_p = new N(key, mp[h]);
        mp[h] = new_p;
    }

    void remove(int key)
    {
        int h = key % M;
        N *ptr = mp[h];
        N *lst = nullptr;
        while (ptr != nullptr)
        {
            if (ptr->val == key)
            {
                if (lst == nullptr)
                    mp[h] = ptr->nxt;
                else
                    lst->nxt = ptr->nxt;
                delete ptr;
                return;
            }
            lst = ptr;
            ptr = ptr->nxt;
        }
    }

    bool contains(int key)
    {
        int h = key % M;
        N *ptr = mp[h];
        while (ptr != nullptr)
        {
            if (ptr->val == key)
                return true;
            ptr = ptr->nxt;
        }
        return false;
    }
};

int main()
{
    io;
    return 0;
}
