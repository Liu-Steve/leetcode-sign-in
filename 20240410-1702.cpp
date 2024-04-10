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
    string maximumBinaryString(string binary)
    {
        int n = binary.size();
        int cnt1 = 0;
        int cnt2 = 0;
        bool start = true;
        for (char ch : binary)
        {
            if (start)
            {
                if (ch == '1')
                    cnt1++;
                else
                    start = false;
            }
            else
            {
                if (ch == '1')
                    cnt2++;
            }
        }
        if (cnt1 == n)
            return binary;
        string str1(n - 1, '1');
        str1.insert(n - 1 - cnt2, "0");
        return str1;
    }
};

int main()
{
    io;
    return 0;
}
