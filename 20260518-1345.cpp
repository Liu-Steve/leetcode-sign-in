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
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> mp;
        unordered_set<int> vis;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        vector<int> jmp(n, -1);
        jmp[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (!vis.count(arr[idx])) {
                for (int nxt : mp[arr[idx]]) {
                    if (nxt == idx || jmp[nxt] != -1) {
                        continue;
                    }
                    jmp[nxt] = jmp[idx] + 1;
                    q.push(nxt);
                }
                vis.insert(arr[idx]);
            }
            if (idx > 0 && jmp[idx - 1] == -1) {
                jmp[idx - 1] = jmp[idx] + 1;
                q.push(idx - 1);
            }
            if (idx < n - 1 && jmp[idx + 1] == -1) {
                jmp[idx + 1] = jmp[idx] + 1;
                q.push(idx + 1);
            }
        }
        return jmp[n - 1];
    }
};

int main() {
    io;
    return 0;
}