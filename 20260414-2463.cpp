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
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());
        int n = factory.size(), m = robot.size();
        vector memo(n, vector<long long>(m, -1));
        auto dfs = [&](auto&& dfs, int i, int j) -> long long {
            if (j < 0) {
                return 0;
            }
            if (i < 0) {
                return LLONG_MAX / 2;
            }
            long long& res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = dfs(dfs, i - 1, j);
            int position = factory[i][0], limit = factory[i][1];
            long long dis_sum = 0;
            for (int k = 1; k <= min(j + 1, limit); k++) {
                dis_sum += abs(robot[j - k + 1] - position);
                res = min(res, dfs(dfs, i - 1, j - k) + dis_sum);
            }
            return res;
        };
        return dfs(dfs, n - 1, m - 1);
    }
};

int main() {
    io;
    return 0;
}