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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0;
        int b = 0;
        vector<int> s_cnt(10);
        vector<int> g_cnt(10);
        int n = secret.size();
        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
            {
                a++;
                continue;
            }
            s_cnt[secret[i] - '0']++;
            g_cnt[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; ++i)
            b += min(s_cnt[i], g_cnt[i]);
        stringstream ss;
        ss << a << 'A' << b << 'B';
        return ss.str();
    }
};

int main()
{
    io;
    return 0;
}
