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

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int, vector<int>, less<int>> down;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (up.empty()) {
            up.push(num);
            return;
        }
        if (num >= up.top()) {
            up.push(num);
            while (up.size() - down.size() > 1) {
                down.push(up.top());
                up.pop();
            }
        } else {
            down.push(num);
            while (down.size() > up.size()) {
                up.push(down.top());
                down.pop();
            }
        }
    }

    double findMedian() {
        if (up.size() > down.size()) {
            return up.top();
        } else {
            return (up.top() + down.top()) / 2.0;
        }
    }
};

int main() {
    io;
    return 0;
}