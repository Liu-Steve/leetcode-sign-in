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

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<pair<int, int>> dp1(n + 1, {-1, INT32_MAX}), dp2(n + 1, {-1, INT32_MAX});
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                char ch = board[i - 1][j - 1];
                if (ch == 'E') {
                    dp2[j] = {0, 1};
                    continue;
                } else if (ch == 'S') {
                    ch = '0';
                } else if (ch == 'X') {
                    dp2[j] = {-1, INT32_MAX};
                    continue;
                }
                if (dp2[j - 1].second == INT32_MAX && dp1[j].second == INT32_MAX && dp1[j - 1].second == INT32_MAX) {
                    dp2[j] = {-1, INT32_MAX};
                    continue;
                }
                int score = max({dp2[j - 1].first, dp1[j].first, dp1[j - 1].first});
                int plan = 0;
                if (dp2[j - 1].first == score) {
                    plan = (plan + dp2[j - 1].second) % MOD;
                }
                if (dp1[j].first == score) {
                    plan = (plan + dp1[j].second) % MOD;
                }
                if (dp1[j - 1].first == score) {
                    plan = (plan + dp1[j - 1].second) % MOD;
                }
                dp2[j] = {score + ch - '0', plan};
            }
            swap(dp1, dp2);
        }
        if (dp1.back().second == INT32_MAX) {
            return {0, 0};
        }
        return {dp1.back().first, dp1.back().second};
    }
};

int main() {
    io;
    return 0;
}