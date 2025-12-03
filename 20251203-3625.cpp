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
    int countTrapezoids(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<double, vector<double>> trape;
        unordered_map<int, vector<double>> para;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                double k = x1 == x2 ? 2001 : (double)(y1 - y2) / (x1 - x2);
                double b = x1 == x2 ? x1 : (double)(x1 * y2 - x2 * y1) / (x1 - x2);
                int c = (x1 + x2 + 4000) + ((y1 + y2 + 4000) << 16);
                trape[k].push_back(b);
                para[c].push_back(k);
            }
        int sum = 0;
        for (auto &[c, vk] : para)
        {
            if (vk.size() < 2)
                continue;
            unordered_map<double, int> cnt;
            for (auto k : vk)
                cnt[k]++;
            int pre = 0;
            for (auto [k, v] : cnt)
            {
                sum -= pre * v;
                pre += v;
            }
        }
        for (auto &[c, vk] : trape)
        {
            if (vk.size() < 2)
                continue;
            unordered_map<double, int> cnt;
            for (auto k : vk)
                cnt[k]++;
            int pre = 0;
            for (auto [k, v] : cnt)
            {
                sum += pre * v;
                pre += v;
            }
        }
        return sum;
    }
};

int main()
{
    io;

    Solution s;
    vv val{{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}, {-3, 0}};
    cout << s.countTrapezoids(val) << endl;

    return 0;
}
