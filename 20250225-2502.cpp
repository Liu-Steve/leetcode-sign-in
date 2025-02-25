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

class Allocator
{
private:
    vector<int> mem;
    int n;

public:
    Allocator(int n) : mem(n), n(n)
    {
    }

    int allocate(int size, int mID)
    {
        int target = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mem[i] != 0)
            {
                target = i + 1;
                cnt = 0;
                continue;
            }
            cnt++;
            if (cnt < size)
                continue;
            for (int j = target; j <= i; ++j)
                mem[j] = mID;
            return target;
        }
        return -1;
    }

    int freeMemory(int mID)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (mem[i] == mID)
            {
                ans++;
                mem[i] = 0;
            }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
