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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pre(numCourses);
        vector<vector<int>> nxt(numCourses);
        for (auto& p : prerequisites) {
            nxt[p[1]].push_back(p[0]);
            pre[p[0]]++;
        }
        int complete = 0;
        queue<int> learn;
        for (int i = 0; i < numCourses; ++i) {
            if (pre[i] == 0) {
                learn.push(i);
            }
        }
        while (!learn.empty()) {
            int fa = learn.front();
            learn.pop();
            complete++;
            for (int ch : nxt[fa]) {
                pre[ch]--;
                if (pre[ch] == 0) {
                    learn.push(ch);
                }
            }
        }
        return complete == numCourses;
    }
};

int main() {
    io;
    return 0;
}