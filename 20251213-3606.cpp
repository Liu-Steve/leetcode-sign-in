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

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        int n = code.size();
        vector<int> idx;
        for (int i = 0; i < n; ++i)
        {
            if (!isActive[i])
                continue;
            if (businessLine[i] != "electronics" &&
                businessLine[i] != "grocery" &&
                businessLine[i] != "pharmacy" &&
                businessLine[i] != "restaurant")
                continue;
            if (code[i] == "")
                continue;
            bool v = true;
            for (char ch : code[i])
            {
                if (ch >= 'a' && ch <= 'z' ||
                    ch >= 'A' && ch <= 'Z' ||
                    ch >= '0' && ch <= '9' ||
                    ch == '_')
                    continue;
                v = false;
                break;
            }
            if (v)
                idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&](int idx1, int idx2)
             {
            if (businessLine[idx1] != businessLine[idx2])
                return businessLine[idx1] < businessLine[idx2];
            return code[idx1] < code[idx2]; });
        vector<string> ans;
        for (int id : idx)
            ans.push_back(code[id]);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
