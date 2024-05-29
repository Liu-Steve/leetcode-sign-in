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
    int maximumLength(string s)
    {
        vector<vector<int>> cnt(26);
        char lst = s[0];
        int len = 0;
        for (char ch : s)
        {
            if (ch == lst)
            {
                len++;
                continue;
            }
            cnt[lst - 'a'].push_back(len);
            lst = ch;
            len = 1;
        }
        cnt[lst - 'a'].push_back(len);
        int ans = -1;
        for (auto &v : cnt)
        {
            if (reduce(v.begin(), v.end()) < 3)
                continue;
            sort(v.begin(), v.end(), greater<int>());
            if (v.size() == 1 || v[0] - 2 >= v[1])
                ans = max(ans, v[0] - 2);
            else if (v.size() >= 3 && v[0] == v[2])
                ans = max(ans, v[0]);
            else
                ans = max(ans, v[0] - 1);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
