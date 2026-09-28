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
    string evaluate(string_view s, vector<vector<string>>& knowledge) {
        unordered_map<string_view, string*> k;
        for (vector<string>& v : knowledge) k.emplace(v[0], &(v[1]));
        ostringstream o;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] != '(') {
                o << s[i];
                continue;
            }
            int j = 0;
            for (j = i + 1; s[j] != ')'; ++j);
            string_view sv = s.substr(i + 1, j - 1 - i);
            if (k.find(sv) == k.end())
                o << '?';
            else
                o << *(k[sv]);
            i = j;
        }
        return o.str();
    }
};

int main() {
    io;
    return 0;
}