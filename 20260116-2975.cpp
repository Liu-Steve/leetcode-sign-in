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
  int maximizeSquareArea(int m, int n, vector<int> &hFences,
                         vector<int> &vFences) {
    hFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);
    unordered_set<long long> d;
    for (int i = 0; i < hFences.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        d.insert(abs(hFences[i] - hFences[j]));
      }
    }
    long long ans = -1;
    for (int i = 0; i < vFences.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        long long v = abs(vFences[i] - vFences[j]);
        if (d.count(v)) {
          ans = max(ans, v * v);
        }
      }
    }
    return ans % MOD;
  }
};

int main() {
  io;
  return 0;
}