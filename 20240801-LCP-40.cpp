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

class Solution
{
public:
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        sort(cards.begin(), cards.end(), greater<int>());
        vector<int> odd(1);
        vector<int> even(1);
        for (int c : cards)
            if (c % 2 == 1)
                odd.push_back(c + odd.back());
            else
                even.push_back(c + even.back());
        int ans = 0;
        for (int i = 0; i <= cnt && i < odd.size(); i += 2)
            if (cnt - i >= 0 && cnt - i < even.size())
                ans = max(ans, odd[i] + even[cnt - i]);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
