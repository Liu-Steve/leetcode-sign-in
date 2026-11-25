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

typedef struct st {
    int len;
    int link;
    unordered_map<int, int> next;
    st(int len, int link) : len(len), link(link) {}
} State;

class SAM {
private:
    int size;
    int last;
    vector<State> st;

public:
    SAM() : size(1), last(0) {
        st.emplace_back(0, -1);
    }

    void extend(int c) {
        int cur = size++;
        st.emplace_back(st[last].len + 1, 0);
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = size++;
                st.emplace_back(st[p].len + 1, st[q].link);
                st[clone].next = st[q].next;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    int solve() {
        vector<bool> hasChild(size, false);
        for (int u = 1; u < size; ++u) {
            hasChild[st[u].link] = true;
        }
        int ans = INT32_MAX;
        for (int u = 1; u < size; ++u) {
            if (!hasChild[u]) {
                ans = min(ans, st[st[u].link].len + 1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        SAM sam;
        for (int num : nums) {
            sam.extend(num);
        }
        return sam.solve();
    }
};

int main() {
    io;
    return 0;
}
