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
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }
        vector dp(n + 1, vector<int>(n + 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 2; j >= 0; --j) {
                for (int k = j + 1; k < i; ++k) {
                    int sum1 = pre[k] - pre[j];
                    int sum2 = pre[i] - pre[k];
                    int s1 = dp[j][k];
                    int s2 = dp[k][i];
                    int score;
                    if (sum1 < sum2) {
                        score = sum1 + s1;
                    } else if (sum1 > sum2) {
                        score = sum2 + s2;
                    } else {
                        score = sum1 + max(s1, s2);
                    }
                    dp[j][i] = max(dp[j][i], score);
                }
            }
        }
        return dp[0][n];
    }
};

int main() {
    io;
    return 0;
}