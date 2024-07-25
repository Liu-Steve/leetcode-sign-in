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
    int minimumOperations(string num)
    {
        int cnt = num.size();
        int sta = 0;
        for (auto it = num.rbegin(); it != num.rend(); it++)
        {
            if (sta == 0)
            {
                if (*it == '0')
                    sta++;
                continue;
            }
            if (*it == '0' || *it == '5')
            {
                sta++;
                cnt = min(cnt, (int)(it - num.rbegin()) - 1);
                break;
            }
        }
        if (sta == 1)
            cnt--;
        sta = 0;
        for (auto it = num.rbegin(); it != num.rend(); it++)
        {
            if (sta == 0)
            {
                if (*it == '5')
                    sta++;
                continue;
            }
            if (*it == '2' || *it == '7')
            {
                sta++;
                cnt = min(cnt, (int)(it - num.rbegin()) - 1);
                break;
            }
        }
        return cnt;
    }
};

int main()
{
    io;
    return 0;
}
