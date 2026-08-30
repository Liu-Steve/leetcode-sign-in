#include <bits/stdc++.h>

#include <vector>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p = head->next;
        int lst = head->val;
        int idx = 1;
        int lst_idx = -1;
        int fst_idx = -1;
        vector<int> ans{INT32_MAX, -1};
        while (p->next != nullptr) {
            if (p->val > lst && p->val > p->next->val || p->val < lst && p->val < p->next->val) {
                if (fst_idx == -1) {
                    fst_idx = idx;
                    lst_idx = idx;
                } else {
                    ans[0] = min(ans[0], idx - lst_idx);
                    ans[1] = idx - fst_idx;
                    lst_idx = idx;
                }
            }
            lst = p->val;
            p = p->next;
            idx++;
        }
        if (fst_idx == lst_idx) {
            return {-1, -1};
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}