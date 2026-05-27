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
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        typedef struct sta {
            vector<int> nxt;
            int idx;
            int len;
            sta(int idx, int len) : nxt(26, -1), idx(idx), len(len) {}
            void update(int i, int t) {
                if (t < len) {
                    len = t;
                    idx = i;
                }
            }
        } State;
        vector<State> trie;
        trie.emplace_back(-1, INT32_MAX);
        for (int wi = 0; wi < wordsContainer.size(); ++wi) {
            int p = 0;
            string& w = wordsContainer[wi];
            trie[p].update(wi, w.size());
            for (int i = w.size() - 1; i >= 0; --i) {
                int e = w[i] - 'a';
                if (trie[p].nxt[e] != -1) {
                    p = trie[p].nxt[e];
                    trie[p].update(wi, w.size());
                    continue;
                }
                int np = trie.size();
                trie.emplace_back(wi, w.size());
                trie[p].nxt[e] = np;
                p = np;
                trie[p].update(wi, w.size());
            }
        }
        vector<int> ans;
        for (string& q : wordsQuery) {
            int p = 0;
            for (int i = q.size() - 1; i >= 0; --i) {
                int e = q[i] - 'a';
                if (trie[p].nxt[e] == -1) {
                    break;
                }
                p = trie[p].nxt[e];
            }
            ans.push_back(trie[p].idx);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}