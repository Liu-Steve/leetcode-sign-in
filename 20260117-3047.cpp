#include "bits/stdc++.h"
#include <vector>
#define io                                                                     \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);                                                                  \
  cout.tie(0)
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    long long ans = 0;
    int n = bottomLeft.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int b1 = bottomLeft[i][0];
        int b2 = bottomLeft[j][0];
        int l1 = bottomLeft[i][1];
        int l2 = bottomLeft[j][1];
        int t1 = topRight[i][0];
        int t2 = topRight[j][0];
        int r1 = topRight[i][1];
        int r2 = topRight[j][1];
        if (b1 >= t2 || b2 >= t1 || l1 >= r2 || l2 >= r1) {
          continue;
        }
        vector<long long> h{b1, b2, t1, t2};
        sort(h.begin(), h.end());
        vector<long long> w{l1, l2, r1, r2};
        sort(w.begin(), w.end());
        ans = max(ans, min(h[2] - h[1], w[2] - w[1]));
      }
    }
    return ans * ans;
  }
};

int main() {
  io;
  return 0;
}