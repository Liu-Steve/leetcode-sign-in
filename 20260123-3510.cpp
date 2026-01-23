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

typedef struct element {
  long long val;
  int front;
  int back;
  bool removed;
} Element;

typedef struct sum {
  long long val;
  int left;
  int right;
  sum() {}
  sum(long long val, int left, int right) : val(val), left(left), right(right) {}
  bool operator<(const struct sum &other) const {
    if (val != other.val) {
      return val > other.val;
    } else if (left != other.left) {
      return left > other.left;
    } else {
      return right > other.right;
    }
  }
} Sum;

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size();
    vector<Element> arr(n);
    for (int i = 0; i < n; ++i) {
      arr[i].val = nums[i];
      arr[i].front = i - 1;
      arr[i].back = i + 1;
      arr[i].removed = false;
    }
    arr[0].front = -1;
    arr[n - 1].back = -1;
    priority_queue<Sum> pq;
    int re = 0;
    for (int i = 0; i + 1 < n; ++i) {
      pq.emplace(nums[i] + nums[i + 1], i, i + 1);
      if (nums[i] > nums[i + 1]) {
        re++;
      }
    }
    int cnt = 0;
    while (re > 0) {
      Sum s = pq.top();
      pq.pop();
      if (arr[s.left].removed || arr[s.right].removed ||
          arr[s.left].val + arr[s.right].val != s.val) {
        continue;
      }
      arr[s.right].removed = true;
      if (arr[s.left].val > arr[s.right].val) {
        re--;
      }
      int l = arr[s.left].front;
      int r = arr[s.right].back;
      arr[s.left].back = r;
      if (l != -1) {
        if (arr[l].val > arr[s.left].val) {
          re--;
        }
        if (arr[l].val > arr[s.left].val + arr[s.right].val) {
          re++;
        }
        pq.emplace(arr[l].val + arr[s.left].val + arr[s.right].val, l, s.left);
      }
      if (r != -1) {
        if (arr[s.right].val > arr[r].val) {
          re--;
        }
        if (arr[s.left].val + arr[s.right].val > arr[r].val) {
          re++;
        }
        arr[r].front = s.left;
        pq.emplace(arr[s.left].val + arr[s.right].val + arr[r].val, s.left, r);
      }
      arr[s.left].val += arr[s.right].val;
      cnt++;
    }
    return cnt;
  }
};

int main() {
  io;
  Solution s;
  vector<int> nums{-2, 1, 2, -1, -1, -2, -2, -1, -1, 1, 1};
  cout << s.minimumPairRemoval(nums);
  return 0;
}