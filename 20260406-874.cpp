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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> hm;
        auto h = [](int a, int b) {
            return (a << 16) | (b & 0xffff);
        };
        for (auto& ob : obstacles) {
            hm.insert(h(ob[0], ob[1]));
        }
        int x = 0;
        int y = 0;
        int ans = 0;
        int d = 0;
        vector<int> b{0, 1, 0, -1, 0};
        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
                continue;
            } else if (c == -1) {
                d = (d + 1) % 4;
                continue;
            }
            while (c--) {
                int nx = x + b[d];
                int ny = y + b[d + 1];
                if (hm.count(h(nx, ny))) {
                    break;
                }
                x = nx;
                y = ny;
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}