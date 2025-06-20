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
    int maxDistance(string s, int k)
    {
        int ans = 0;
        map<char, char> mp = {
            {'N', 'S'}, {'S', 'N'}, {'E', 'W'}, {'W', 'E'}};
        auto f = [&](char ch1, char ch2)
        {
            int dis1 = 0;
            int dis2 = 0;
            int op = k;
            for (char ch : s)
            {
                if (ch == ch1)
                    dis1++;
                else if (ch == ch2)
                    dis2++;
                else if (mp[ch] == ch1)
                {
                    if (op)
                    {
                        op--;
                        dis1++;
                    }
                    else
                        dis1--;
                }
                else
                {
                    if (op)
                    {
                        op--;
                        dis2++;
                    }
                    else
                        dis2--;
                }
                ans = max(ans, abs(dis1) + abs(dis2));
            }
        };
        f('N', 'E');
        f('N', 'W');
        f('S', 'E');
        f('S', 'W');
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
