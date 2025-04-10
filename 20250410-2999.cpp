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
private:
    long long cal(string &x, string &s, int limit)
    {
        if (x.size() < s.size())
            return 0;
        if (x.size() == s.size())
            return x >= s ? 1 : 0;
        int preLen = x.size() - s.size();
        long long count = 0;
        for (int i = 0; i < preLen; ++i)
        {
            if (limit < x[i] - '0')
            {
                count += (long long)pow(limit + 1, preLen - i);
                return count;
            }
            count += (long long)(x[i] - '0') * (long long)pow(limit + 1, preLen - 1 - i);
        }
        string suffix = x.substr(preLen);
        if (suffix >= s)
            count++;
        return count;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        string start_ = to_string(start - 1);
        string finish_ = to_string(finish);
        return cal(finish_, s, limit) - cal(start_, s, limit);
    }
};

int main()
{
    io;
    return 0;
}
