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
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for (int right = 0; right < heights.size(); ++right) {
            while (st.size() > 1 && heights[st.top()] >= heights[right]) {
                int i = st.top();
                st.pop();
                int left = st.top();
                ans = max(ans, heights[i] * (right - left - 1));
            }
            st.push(right);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}