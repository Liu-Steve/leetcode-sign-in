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
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                             vector<int> &vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());
    int ans1 = 0;
    int lst = 0;
    int cnt = 0;
    for (int h : hBars) {
      if (h == lst + 1) {
        cnt++;
      } else {
        cnt = 1;
      }
      ans1 = max(ans1, cnt);
      lst = h;
    }
    int ans2 = 0;
    lst = 0;
    cnt = 0;
    for (int v : vBars) {
      if (v == lst + 1) {
        cnt++;
      } else {
        cnt = 1;
      }
      ans2 = max(ans2, cnt);
      lst = v;
    }
    int ans = min(ans1, ans2) + 1;
    return ans * ans;
  }
};

int main() {
  io;
  return 0;
}