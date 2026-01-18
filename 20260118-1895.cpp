#include "bits/stdc++.h"
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
  int largestMagicSquare(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector vertical(m + 1, vector(n + 1, 0));
    vector horizontal(m + 1, vector(n + 1, 0));
    vector main_diagonal(m + 1, vector(n + 1, 0));
    vector counter_diagonal(m + 1, vector(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        vertical[i + 1][j + 1] = vertical[i][j + 1] + grid[i][j];
        horizontal[i + 1][j + 1] = horizontal[i + 1][j] + grid[i][j];
        main_diagonal[i + 1][j + 1] = main_diagonal[i][j] + grid[i][j];
        counter_diagonal[i + 1][j] =
            counter_diagonal[i][j + 1] + grid[i][j];
      }
    }
    for (int k = min(m, n); k >= 2; --k) {
      for (int i = 0; i <= m - k; ++i) {
        for (int j = 0; j <= n - k; ++j) {
          int sum = main_diagonal[i + k][j + k] - main_diagonal[i][j];
          if (counter_diagonal[i + k][j] - counter_diagonal[i][j + k] != sum) {
            continue;
          }
          int invalid = false;
          for (int t = i + 1; t <= i + k; ++t) {
            if (horizontal[t][j + k] - horizontal[t][j] != sum) {
              invalid = true;
              break;
            }
          }
          if (invalid) {
            continue;
          }
          for (int t = j + 1; t <= j + k; ++t) {
            if (vertical[i + k][t] - vertical[i][t] != sum) {
              invalid = true;
              break;
            }
          }
          if (invalid) {
            continue;
          }
          return k;
        }
      }
    }
    return 1;
  }
};

int main() {
  io;
  return 0;
}