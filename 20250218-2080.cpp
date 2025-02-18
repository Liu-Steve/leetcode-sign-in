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

class RangeFreqQuery
{
private:
    unordered_map<int, vector<int>> idx;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            if (!idx.count(arr[i]))
                idx[arr[i]] = vector<int>{i};
            else
                idx[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (!idx.count(value))
            return 0;
        auto &p = idx[value];
        auto l = upper_bound(p.begin(), p.end(), left - 1);
        auto r = upper_bound(p.begin(), p.end(), right);
        return r - l;
    }
};

int main()
{
    io;
    return 0;
}
