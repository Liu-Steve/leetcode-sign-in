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

constexpr double EPS = 1e-6;
function<double(double, double)> ops[] = {
    plus{}, minus{}, multiplies{}, divides{},
    [](auto a, auto b)
    { return b - a; },
    [](auto a, auto b)
    { return b / a; }};

class Solution
{
public:
    bool judgePoint24(const auto &cards)
    {
        if (cards.size() == 1)
            return abs(cards[0] - 24) < EPS;
        for (int i = 0; i < cards.size(); i++)
        {
            for (int j = i + 1; j < cards.size(); j++)
            {
                auto a = cards[i], b = cards[j];
                vector<double> tmp(cards.begin(), cards.end());
                tmp.erase(tmp.begin() + j);
                for (auto &&op : ops)
                {
                    tmp[i] = op(a, b);
                    if (judgePoint24(tmp))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.judgePoint24(vector{1, 3, 6, 7}) << endl;
    return 0;
}
