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
private:
    bool isSub(string &s1, string &s2)
    {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s1.size() && p2 < s2.size())
        {
            if (s1[p1] == s2[p2])
                p1++;
            p2++;
        }
        return p1 == s1.size();
    }

public:
    int findLUSlength(vector<string> &strs)
    {
        sort(strs.begin(), strs.end(), [&](string &s1, string &s2)
             {
            if (s1.size() != s2.size())
                return s1.size() > s2.size();
            return s1 < s2; });
        for (int i = 0; i < strs.size(); ++i)
        {
            if (i < strs.size() - 1 && strs[i] == strs[i + 1])
                continue;
            bool sub = false;
            for (int j = 0; j < i; ++j)
                if (isSub(strs[i], strs[j]))
                {
                    sub = true;
                    break;
                }
            if (!sub)
                return strs[i].size();
        }
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
