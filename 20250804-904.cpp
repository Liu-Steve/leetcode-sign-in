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

const long long MOD = 1000000007LL;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int type1 = -1, type2 = -1, t1_begin = 0, t2_begin = 0;
        int l = 0, max_f = 0;
        int len = fruits.size();
        bool end1 = true;
        for (int i = 0; i < len; ++i)
        {
            int f = fruits[i];
            if (f == type1)
            {
                if (!end1)
                {
                    end1 = true;
                    t1_begin = i;
                }
            }
            else if (f == type2)
            {
                if (end1)
                {
                    end1 = false;
                    t2_begin = i;
                }
            }
            else
            {
                if (end1)
                {
                    end1 = false;
                    l = t1_begin;
                    type2 = f;
                    t2_begin = i;
                }
                else
                {
                    end1 = true;
                    l = t2_begin;
                    type1 = f;
                    t1_begin = i;
                }
            }
            max_f = max(max_f, i - l + 1);
        }
        return max_f;
    }
};

int main()
{
    io;
    return 0;
}
