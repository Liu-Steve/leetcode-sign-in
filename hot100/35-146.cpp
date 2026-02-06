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

class LRUCache {
private:
    queue<int> log;
    unordered_map<int, pair<int, int>> hm;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (hm.count(key)) {
            log.push(key);
            hm[key].second++;
            return hm[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hm.count(key)) {
            hm[key].first = value;
            log.push(key);
            hm[key].second++;
            return;
        }
        hm[key] = {value, 1};
        log.push(key);
        while (hm.size() > capacity) {
            int out = log.front();
            log.pop();
            hm[out].second--;
            if (hm[out].second <= 0) {
                hm.erase(out);
            }
        }
    }
};

int main() {
    io;
    return 0;
}