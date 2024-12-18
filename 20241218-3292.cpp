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

typedef struct node
{
    int nxt[26];
    int fail;
    int len;
    node()
    {
        memset(nxt, 0, sizeof(nxt));
        fail = 0;
        len = 0;
    }
    int &operator[](int idx)
    {
        return nxt[idx];
    }
} Node;

class AC
{
private:
    vector<Node> trie;
    int now;

public:
    AC()
    {
        trie.emplace_back();
        now = 0;
    }

    void insert(string &str)
    {
        int u = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            char ch = str[i];
            int c = ch - 'a';
            if (trie[u][c] != 0)
            {
                u = trie[u][c];
                continue;
            }
            trie.emplace_back();
            int nxt_idx = trie.size() - 1;
            trie[u][c] = nxt_idx;
            u = nxt_idx;
            trie[u].len = i + 1;
        }
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (trie[0][i])
                q.push(trie[0][i]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i)
                if (trie[u][i])
                {
                    // child's fail is the next of father's fail
                    trie[trie[u][i]].fail = trie[trie[u].fail][i];
                    q.push(trie[u][i]);
                }
                else
                    trie[u][i] = trie[trie[u].fail][i];
        }
    }

    int query(char ch)
    {
        int c = ch - 'a';
        now = trie[now][c];
        return trie[now].len;
    }
};

class Solution
{
public:
    int minValidStrings(vector<string> &words, string target)
    {
        AC ac;
        for (string &w : words)
            ac.insert(w);
        ac.build();
        int n = target.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int len = ac.query(target[i]);
            if (len == 0)
                return -1;
            dp[i + 1] = dp[i + 1 - len] + 1;
        }
        return dp[n];
    }
};

int main()
{
    io;
    return 0;
}
