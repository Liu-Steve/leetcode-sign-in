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

class Trie {
private:
    vector<array<int, 26>> states;
    vector<bool> end;

public:
    Trie() {
        states.emplace_back();
        end.push_back(false);
        states[0].fill(-1);
    }

    void insert(string word) {
        int p = 0;
        for (char ch : word) {
            if (states[p][ch - 'a'] == -1) {
                states[p][ch - 'a'] = states.size();
                p = states.size();
                states.emplace_back();
                end.push_back(false);
                states[p].fill(-1);
            } else {
                p = states[p][ch - 'a'];
            }
        }
        end[p] = true;
    }

    bool search(string word) {
        int p = 0;
        for (char ch : word) {
            if (states[p][ch - 'a'] == -1) {
                return false;
            } else {
                p = states[p][ch - 'a'];
            }
        }
        return end[p];
    }

    bool startsWith(string prefix) {
        int p = 0;
        for (char ch : prefix) {
            if (states[p][ch - 'a'] == -1) {
                return false;
            } else {
                p = states[p][ch - 'a'];
            }
        }
        return true;
    }
};

int main() {
    io;
    return 0;
}