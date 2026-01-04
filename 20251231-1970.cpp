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
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    vector mp(row, vector<int>(col));
    int start = row * col;
    int end = row * col + 1;
    vector<int> fa(row * col + 2, -1);
    auto findFa = [&](auto &&findFa, int num) -> int {
      return fa[num] < 0 ? num : fa[num] = findFa(findFa, fa[num]);
    };
    auto uni = [&](auto &&findFa, int num1, int num2) {
      int fa1 = findFa(findFa, num1);
      int fa2 = findFa(findFa, num2);
      if (fa1 == fa2) {
        return;
      }
      if (fa[fa1] < fa[fa2]) {
        fa[fa1] += fa[fa2];
        fa[fa2] = fa1;
      } else {
        fa[fa2] += fa[fa1];
        fa[fa1] = fa2;
      }
    };
    for (auto it = cells.rbegin(); it != cells.rend(); ++it) {
      int i = (*it)[0] - 1;
      int j = (*it)[1] - 1;
      mp[i][j] = true;
      if (i + 1 < row && mp[i + 1][j]) {
        uni(findFa, i * col + j, (i + 1) * col + j);
      }
      if (j + 1 < col && mp[i][j + 1]) {
        uni(findFa, i * col + j, i * col + j + 1);
      }
      if (i - 1 >= 0 && mp[i - 1][j]) {
        uni(findFa, i * col + j, (i - 1) * col + j);
      }
      if (j - 1 >= 0 && mp[i][j - 1]) {
        uni(findFa, i * col + j, i * col + j - 1);
      }
      if (i == 0) {
        uni(findFa, i * col + j, start);
      }
      if (i == row - 1) {
        uni(findFa, i * col + j, end);
      }
      if (findFa(findFa, start) == findFa(findFa, end)) {
        return cells.rend() - it - 1;
      }
    }
    return -1;
  }
};

int main() {
  io;
  return 0;
}