#include <bits/stdc++.h>

#include <vector>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2)
    {
        if (x <= x1 && y <= y1)
            return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r;
        else if (x <= x1 && y >= y2)
            return (x1 - x) * (x1 - x) + (y - y2) * (y - y2) <= r * r;
        else if (x >= x2 && y <= y1)
            return (x - x2) * (x - x2) + (y1 - y) * (y1 - y) <= r * r;
        else if (x >= x2 && y >= y2)
            return (x - x2) * (x - x2) + (y - y2) * (y - y2) <= r * r;
        else if (x <= x1)
            return x1 - x <= r;
        else if (x >= x2)
            return x - x2 <= r;
        else if (y <= y1)
            return y1 - y <= r;
        else if (y >= y2)
            return y - y2 <= r;
        return true;
    }
};

int main() {
    io;
    return 0;
}