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
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        int m = sqrt(n);
        int section = (n / m) + (n % m > 0);
        vector<int> maxV(section);
        for (int i = 0; i < maxV.size(); ++i)
        {
            int l = m * i;
            int r = min(m * (i + 1), n);
            maxV[i] = *max_element(baskets.begin() + l, baskets.begin() + r);
        }
        auto update = [&](int f, int i) -> void
        {
            int l = m * i;
            int r = min(m * (i + 1), n);
            for (int j = l; j < r; ++j)
            {
                if (f > baskets[j])
                    continue;
                baskets[j] = 0;
                maxV[i] = *max_element(baskets.begin() + l, baskets.begin() + r);
                break;
            }
        };
        int ans = 0;
        for (int f : fruits)
        {
            bool find = false;
            for (int i = 0; i < maxV.size(); ++i)
            {
                if (f > maxV[i])
                    continue;
                update(f, i);
                find = true;
                break;
            }
            if (!find)
                ans++;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
