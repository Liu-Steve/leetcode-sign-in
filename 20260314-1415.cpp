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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

constexpr long long MOD = 1000000007LL;

class Solution {
public:
    string getHappyString(int n, int k) {
        k--;
        if (k >= (1 << n) + (1 << (n - 1))) {
            return "";
        }
        string ans = "";
        if (k & (1 << n)) {
            ans.push_back('c');
        } else {
            ans.push_back('a' + (bool)(k & (1 << (n - 1))));
        }
        for (int i = n - 2; i >= 0; --i) {
            char lst = ans.back();
            bool up = k & (1 << i);
            if (up) {
                switch (lst) {
                    case 'a':
                    case 'b':
                        ans.push_back('c');
                        break;
                    case 'c':
                        ans.push_back('b');
                    default:
                        break;
                }
            } else {
                switch (lst) {
                    case 'b':
                    case 'c':
                        ans.push_back('a');
                        break;
                    case 'a':
                        ans.push_back('b');
                    default:
                        break;
                }
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