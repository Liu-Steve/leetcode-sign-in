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
    int maxDifference(string s, int k)
    {
        const int inf = INT_MAX / 2;
        int ans = -inf;
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (y == x)
                    continue;
                vector<int> cur_s(5), pre_s(5);
                int min_s[2][2] = {{inf, inf}, {inf, inf}};
                int left = 0;
                for (int i = 0; i < s.size(); i++)
                {
                    cur_s[s[i] - '0']++;
                    int r = i + 1;
                    while (r - left >= k && cur_s[x] > pre_s[x] && cur_s[y] > pre_s[y])
                    {
                        int &p = min_s[pre_s[x] & 1][pre_s[y] & 1];
                        p = min(p, pre_s[x] - pre_s[y]);
                        pre_s[s[left] - '0']++;
                        left++;
                    }
                    ans = max(ans, cur_s[x] - cur_s[y] - min_s[cur_s[x] & 1 ^ 1][cur_s[y] & 1]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
