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
    int numOfStrings(vector<string>& patterns, string word) {
        typedef struct st {
            char ch;
            short end;
            vector<int> nxt;
            st(char ch) : ch(ch), end(0), nxt(26, -1) {}
        } Status;
        vector<Status> trie;
        trie.emplace_back(' ');
        for (string& p : patterns) {
            int idx = 0;
            for (char ch : p) {
                if (trie[idx].nxt[ch - 'a'] != -1) {
                    idx = trie[idx].nxt[ch - 'a'];
                    continue;
                }
                int jmp = trie.size();
                trie.emplace_back(ch);
                trie[idx].nxt[ch - 'a'] = jmp;
                idx = jmp;
            }
            trie[idx].end++;
        }
        int n = word.size();
        unordered_set<int> fnd;
        for (int i = 0; i < n; ++i) {
            int idx = 0;
            for (int j = i; j < n; ++j) {
                int ch = word[j] - 'a';
                if (trie[idx].nxt[ch] == -1) {
                    break;
                }
                idx = trie[idx].nxt[ch];
                if (trie[idx].end) {
                    fnd.insert(idx);
                }
            }
        }
        int ans = 0;
        for (int q : fnd) {
            ans += trie[q].end;
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}