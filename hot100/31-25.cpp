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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* node0 = &dummy;
        while (true) {
            ListNode* node1 = node0;
            bool end = false;
            for (int i = 0; i < k; ++i) {
                node1 = node1->next;
                if (node1 == nullptr) {
                    end = true;
                    break;
                }
            }
            if (end) {
                break;
            }
            ListNode* node2 = node1->next;
            node1->next = nullptr;
            ListNode* pre = node0;
            ListNode* now = node0->next;
            while (now) {
                ListNode* temp = now->next;
                now->next = pre;
                pre = now;
                now = temp;
            }
            ListNode* node3 = node0->next;
            node3->next = node2;
            node0->next = node1;
            node0 = node3;
        }
        return dummy.next;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}