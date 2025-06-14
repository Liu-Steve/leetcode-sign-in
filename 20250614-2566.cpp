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
    int minMaxDifference(int num)
    {
        int min_num = num;
        for (int i = 1; i <= 9; ++i)
        {
            int new_num = num;
            int bias = 1;
            while (bias <= num)
            {
                if ((new_num / bias) % 10 != i)
                {
                    bias *= 10;
                    continue;
                }
                new_num -= i * bias;
                bias *= 10;
            }
            min_num = min(min_num, new_num);
        }
        int max_num = num;
        for (int i = 0; i <= 8; ++i)
        {
            int new_num = num;
            int bias = 1;
            while (bias <= num)
            {
                if ((new_num / bias) % 10 != i)
                {
                    bias *= 10;
                    continue;
                }
                new_num += (9 - i) * bias;
                bias *= 10;
            }
            max_num = max(max_num, new_num);
        }
        return max_num - min_num;
    }
};

int main()
{
    io;
    return 0;
}
