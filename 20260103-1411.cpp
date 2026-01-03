#include "bits/stdc++.h"
#include <numeric>
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
  int numOfWays(int n) {
    vector<vector<int>> mat{
        {0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
    };
    vector<long long> cnt1(12, 1), cnt2(12);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 12; ++j) {
        cnt2[j] = 0;
        for (int k = 0; k < 12; ++k) {
          cnt2[j] += cnt1[k] * mat[j][k];
        }
        cnt2[j] %= MOD;
      }
      swap(cnt1, cnt2);
    }
    return reduce(cnt1.begin(), cnt1.end(), 0ll) % MOD;
  }
};

int main() {
  io;
  return 0;
}