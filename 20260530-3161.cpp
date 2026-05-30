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
    vector<int> t;

    void update(int i, int val) {
        for (; i < t.size(); i += i & -i) {
            t[i] = max(t[i], val);
        }
    }

    int pre_max(int i) {
        int res = 0;
        for (; i; i &= i - 1) {
            res = max(res, t[i]);
        }
        return res;
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int m = 0;
        vector<int> pos = {0};
        for (auto& q : queries) {
            m = max(m, q[1]);
            if (q[0] == 1) {
                pos.push_back(q[1]);
            }
        }
        m++;
        sort(pos.begin(), pos.end());
        set<int> st(pos.begin(), pos.end());
        st.insert(m);
        t.resize(m);
        for (int i = 1; i < pos.size(); i++) {
            update(pos[i], pos[i] - pos[i - 1]);
        }
        vector<bool> ans;
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];
            int x = q[1];
            auto it = st.lower_bound(x);
            int pre = *prev(it);
            if (q[0] == 1) {
                int nxt = *next(it);
                st.erase(it);
                update(nxt, nxt - pre);
            } else {
                int max_gap = max(pre_max(pre), x - pre);
                ans.push_back(max_gap >= q[2]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    io;
    return 0;
}