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

class Solution
{
public:
    int countTexts(string pressedKeys)
    {
        int cnt = 0;
        char lst = pressedKeys[0];
        vector<int> len3, len4;
        for (char ch : pressedKeys)
        {
            if (ch == lst)
                cnt++;
            else
            {
                if (lst == '7' || lst == '9')
                    len4.push_back(cnt);
                else
                    len3.push_back(cnt);
                cnt = 1;
            }
            lst = ch;
        }
        if (lst == '7' || lst == '9')
            len4.push_back(cnt);
        else
            len3.push_back(cnt);
        auto it3 = max_element(len3.begin(), len3.end());
        auto it4 = max_element(len4.begin(), len4.end());
        int n3 = (it3 == len3.end() ? 0 : *it3);
        int n4 = (it4 == len4.end() ? 0 : *it4);
        vector<vector<int>> dp3(n3 + 2, vector<int>(3));
        vector<vector<int>> dp4(n4 + 2, vector<int>(4));
        dp3[1][0] = 1;
        dp4[1][0] = 1;
        for (int i = 2; i <= n3 + 1; ++i)
        {
            dp3[i][0] = ((long long)dp3[i - 1][0] + dp3[i - 1][1] + dp3[i - 1][2]) % MOD;
            dp3[i][1] = dp3[i - 1][0];
            dp3[i][2] = dp3[i - 1][1];
        }
        for (int i = 2; i <= n4 + 1; ++i)
        {
            dp4[i][0] = ((long long)dp4[i - 1][0] + dp4[i - 1][1] + dp4[i - 1][2] + dp4[i - 1][3]) % MOD;
            dp4[i][1] = dp4[i - 1][0];
            dp4[i][2] = dp4[i - 1][1];
            dp4[i][3] = dp4[i - 1][2];
        }
        long long ans = 1;
        for (int i : len3)
            ans = ans * dp3[i + 1][0] % MOD;
        for (int i : len4)
            ans = ans * dp4[i + 1][0] % MOD;
        return ans;
    }
};

int main()
{
    io;

    Solution s;
    s.countTexts("22233");

    return 0;
}
