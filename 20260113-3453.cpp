#include "bits/stdc++.h"
#include <cstdint>
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
  double separateSquares(vector<vector<int>> &squares) {
    double d = 0, u = INT32_MAX, eps = 1e-6;
    while (u - d > eps) {
      double mid = (u + d) / 2, sum_d = 0, sum_u = 0;
      for (auto &s : squares) {
        long long y = s[1], l = s[2];
        if (mid <= y) {
          sum_u += l * l;
        } else if (mid >= y + l) {
          sum_d += l * l;
        } else {
          sum_d += l * (mid - y);
          sum_u += l * (y + l - mid);
        }
      }
      if (sum_d < sum_u) {
        d = mid;
      } else {
        u = mid;
      }
    }
    return u;
  }
};

int main() {
  io;
  return 0;
}