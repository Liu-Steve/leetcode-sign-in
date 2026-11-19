#include <bits/stdc++.h>
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

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int top1 = 0;
        int top2 = 0;
        int top3 = 0;
        int bot1 = INT32_MAX;
        int bot2 = INT32_MAX;
        int bot3 = INT32_MAX;
        for (int num : nums) {
            if (num > top1) {
                top3 = top2;
                top2 = top1;
                top1 = num;
            } else if (num > top2) {
                top3 = top2;
                top2 = num;
            } else if (num > top3) {
                top3 = num;
            }
            if (num < bot1) {
                bot3 = bot2;
                bot2 = bot1;
                bot1 = num;
            } else if (num < bot2) {
                bot3 = bot2;
                bot2 = num;
            } else if (num < bot3) {
                bot3 = num;
            }
        }
        return min({top1 - bot3, top2 - bot2, top3 - bot1});
    }
};

int main() {
    io;
    return 0;
}
