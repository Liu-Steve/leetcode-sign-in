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
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> pre;
        pre.push_back(0);
        for (int t : travel)
            pre.push_back(t + pre.back());
        int m_cnt = 0;
        int p_cnt = 0;
        int g_cnt = 0;
        int m_lst = 0;
        int p_lst = 0;
        int g_lst = 0;
        for (int i = 0; i < garbage.size(); ++i)
        {
            for (char ch : garbage[i])
            {
                if (ch == 'M')
                {
                    m_cnt++;
                    m_lst = i;
                }
                else if (ch == 'P')
                {
                    p_cnt++;
                    p_lst = i;
                }
                else if (ch == 'G')
                {
                    g_cnt++;
                    g_lst = i;
                }
            }
        }
        return m_cnt + p_cnt + g_cnt + pre[m_lst] + pre[p_lst] + pre[g_lst];
    }
};

int main()
{
    io;
    return 0;
}
