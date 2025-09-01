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
private:
    double d(long long a, long long b)
    {
        double ans = b - a;
        ans /= b * (b + 1);
        return ans;
    }

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extra)
    {
        priority_queue<pair<double, int>> heap;
        int len = classes.size();
        for (int i = 0; i < len; ++i)
            heap.emplace(d(classes[i][0], classes[i][1]), i);
        while (extra--)
        {
            int i = heap.top().second;
            heap.pop();
            classes[i][0]++;
            classes[i][1]++;
            heap.emplace(d(classes[i][0], classes[i][1]), i);
        }
        double ans = 0;
        for (auto &v : classes)
            ans += v[0] / (double)v[1];
        ans /= len;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
