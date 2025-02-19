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

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        pair<int, int> max1{-10001, -1}, max2{-10001, -1},
            min1{10001, -1}, min2{10001, -1};
        int m = arrays.size();
        for (int i = 0; i < m; ++i)
        {
            pair<int, int> num_max{arrays[i].back(), i};
            pair<int, int> num_min{arrays[i].front(), i};
            if (num_max > max1)
            {
                max2 = max1;
                max1 = num_max;
            }
            else if (num_max > max2)
                max2 = num_max;
            if (num_min < min1)
            {
                min2 = min1;
                min1 = num_min;
            }
            else if (num_min < min2)
                min2 = num_min;
        }
        if (max1.second != min1.second)
            return max1.first - min1.first;
        return max(max1.first - min2.first, max2.first - min1.first);
    }
};

int main()
{
    io;
    return 0;
}
