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
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        int n = p.size();
        array<int, 26> p_cnt{}, s_cnt{};
        for (char ch : p) {
            p_cnt[ch - 'a']++;
        }
        for (int i = 0; i < n; ++i) {
            s_cnt[s[i] - 'a']++;
        }
        vector<int> ans;
        if (s_cnt == p_cnt) {
            ans.push_back(0);
        }
        for (int i = 0; i + n < s.size(); ++i) {
            s_cnt[s[i] - 'a']--;
            s_cnt[s[i + n] - 'a']++;
            if (s_cnt == p_cnt) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}