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
    int minimumDistance(string word) {
        auto diff = [&](int p1, int p2) {
            int x1 = p1 / 6;
            int y1 = p1 % 6;
            int x2 = p2 / 6;
            int y2 = p2 % 6;
            return abs(x1 - x2) + abs(y1 - y2);
        };
        vector dp1(26, 0);
        vector dp2(26, 0);
        for (int i = 1; i < word.size(); ++i) {
            int lst = word[i - 1] - 'A';
            int now = word[i] - 'A';
            dp2 = dp1;
            for (int j = 0; j < 26; ++j) {
                dp2[j] += diff(lst, now);
            }
            for (int j = 0; j < 26; ++j) {
                dp2[lst] = min(dp2[lst], dp1[j] + diff(j, now));
            }
            swap(dp1, dp2);
        }
        return *min_element(dp1.begin(), dp1.end());
    }
};

int main() {
    io;
    return 0;
}