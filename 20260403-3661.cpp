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
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size(), m = walls.size();
        struct Pair {
            int x, d;
        };
        vector<Pair> a(n + 2);
        for (int i = 0; i < n; i++) {
            a[i] = {robots[i], distance[i]};
        }
        a[n + 1].x = INT_MAX;
        sort(a.begin(), a.end(), [&](Pair& p1, Pair& p2) {
            return p1.x < p2.x;
        });
        sort(walls.begin(), walls.end());
        int f0 = 0, f1 = 0, left = 0, cur = 0, right0 = 0, right1 = 0;
        for (int i = 1; i <= n; i++) {
            auto [x, d] = a[i];
            int left_x = max(x - d, a[i - 1].x + 1);
            while (left < m && walls[left] < left_x) {
                left++;
            }
            while (cur < m && walls[cur] < x) {
                cur++;
            }
            int cur1 = cur;
            if (cur < m && walls[cur] == x) {
                cur++;
            }
            int left_res = f0 + cur - left;
            auto [x2, d2] = a[i + 1];
            int right_x = min(x + d, x2 - d2 - 1);
            while (right0 < m && walls[right0] <= right_x) {
                right0++;
            }
            f0 = max(left_res, f1 + right0 - cur1);
            right_x = min(x + d, x2 - 1);
            while (right1 < m && walls[right1] <= right_x) {
                right1++;
            }
            f1 = max(left_res, f1 + right1 - cur1);
        }
        return f1;
    }
};

int main() {
    io;
    return 0;
}