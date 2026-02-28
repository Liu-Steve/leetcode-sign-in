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
    string decodeString(string_view s) {
        stringstream ss;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ss << s[i];
                continue;
            }
            int r = 0;
            while (s[i] != '[') {
                r *= 10;
                r += s[i] - '0';
                i++;
            }
            int t = i;
            int p = 0;
            while (p != 1 || s[t] != ']') {
                if (s[t] == '[') {
                    p++;
                } else if (s[t] == ']') {
                    p--;
                }
                t++;
            }
            string sub = decodeString(s.substr(i + 1, t - i - 1));
            for (int j = 0; j < r; ++j) {
                ss << sub;
            }
            i = t;
        }
        return ss.str();
    }
};

int main() {
    io;
    return 0;
}