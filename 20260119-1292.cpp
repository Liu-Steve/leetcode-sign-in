#include "bits/stdc++.h"
#include <functional>
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
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector pre(m + 1, vector(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        pre[i + 1][j + 1] = pre[i][j + 1] + mat[i][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        pre[i + 1][j + 1] += pre[i + 1][j];
      }
    }
    function<bool(int)> q = [&](int k) -> bool {
      for (int i = 0; i + k <= m; ++i) {
        for (int j = 0; j + k <= n; ++j) {
          if (pre[i + k][j + k] + pre[i][j] - pre[i][j + k] - pre[i + k][j] <=
              threshold) {
            return true;
          }
        }
      }
      return false;
    };
    int l = 1;
    int r = min(m, n);
    if (!q(1)) {
      return 0;
    }
    if (q(r)) {
      return r;
    }
    while (l + 1 < r) {
      int k = (l + r) / 2;
      if (q(k)) {
        l = k;
      } else {
        r = k;
      }
    }
    return l;
  }
};

int main() {
  io;
  return 0;
}