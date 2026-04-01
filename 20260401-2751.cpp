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
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int p1, int p2) {
            return positions[p1] < positions[p2];
        });
        stack<int> st;
        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
                continue;
            }
            while (!st.empty()) {
                int j = st.top();
                if (healths[j] > healths[i]) {
                    healths[i] = 0;
                    healths[j]--;
                    break;
                }
                if (healths[j] == healths[i]) {
                    healths[i] = 0;
                    healths[j] = 0;
                    st.pop();
                    break;
                }
                healths[i]--;
                healths[j] = 0;
                st.pop();
            }
        }
        vector<int> ans;
        for (int h : healths) {
            if (h > 0) {
                ans.push_back(h);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}