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

constexpr long long MOD = 1000000007LL;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> s;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        function<void(int)> dfs = [&](int i) -> void {
            for (int j = i; j < n; ++j) {
                s.push_back(candidates[j]);
                sum += candidates[j];
                bool b = false;
                if (sum == target) {
                    ans.push_back(s);
                } else if (sum < target) {
                    dfs(j);
                } else {
                    b = true;
                }
                s.pop_back();
                sum -= candidates[j];
                if (b) {
                    return;
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {
    io;
    return 0;
}