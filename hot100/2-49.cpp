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

struct strHash {
    size_t operator()(const array<int, 26>& arr) const {
        size_t h = 0;
        hash<int> hasher;
        for (int cnt : arr) {
            h = (h << 1) ^ hasher(cnt);
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, int, strHash> hm;
        vector<vector<string>> ans;
        for (string& s : strs) {
            array<int, 26> arr{};
            for (char ch : s) {
                arr[ch - 'a']++;
            }
            if (hm.count(arr)) {
                ans[hm[arr]].push_back(s);
            } else {
                hm[arr] = ans.size();
                ans.push_back(vector<string>{s});
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