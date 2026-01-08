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
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector dp1(n + 1, vector(m + 1, -1000009)),
        dp2(n + 1, vector(m + 1, -1000009));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp1[i + 1][j + 1] =
            max(nums1[i] * nums2[j], max(dp1[i][j + 1], dp1[i + 1][j]));
      }
    }
    int len = 2;
    int ans = dp1[n][m];
    while (len <= min(n, m)) {
      for (int i = len - 1; i < n; ++i) {
        for (int j = len - 1; j < m; ++j) {
          dp2[i + 1][j + 1] = max(dp1[i][j] + nums1[i] * nums2[j],
                                  max(dp2[i][j + 1], dp2[i + 1][j]));
        }
      }
      ans = max(ans, dp2[n][m]);
      swap(dp1, dp2);
      len++;
    }
    return ans;
  }
};

int main() {
  io;
  return 0;
}