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
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT32_MAX;
        int d1 = INT32_MAX;
        for (int i = 0; i < n; ++i) {
            d1 = min(d1, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; ++i) {
            ans = min(ans, max(d1, waterStartTime[i]) + waterDuration[i]);
        }
        int d2 = INT32_MAX;
        for (int i = 0; i < m; ++i) {
            d2 = min(d2, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(d2, landStartTime[i]) + landDuration[i]);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}