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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](ListNode* node1, ListNode* node2) -> bool {
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode ans(0, nullptr);
        ListNode* head = &ans;
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            head->next = node;
            head = node;
            if (node->next != nullptr) {
                pq.push(node->next);
                node->next = nullptr;
            }
        }
        return ans.next;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}