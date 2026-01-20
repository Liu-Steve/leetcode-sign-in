#include "bits/stdc++.h"
#include <cstdint>
#include <unordered_map>
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
  string minWindow(string s, string t) {
    vector<int> cnt_t(128);
    int diff = 0;
    for (char ch : t) {
      if (cnt_t[ch] == 0) {
        diff++;
      }
      cnt_t[ch]++;
    }
    vector<int> cnt_s(128);
    int satis = 0;
    int begin = 0;
    int len = INT32_MAX;
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
      cnt_s[s[i]]++;
      if (satis < diff) {
        if (cnt_s[s[i]] == cnt_t[s[i]]) {
          satis++;
        }
        if (satis < diff) {
          continue;
        }
      }
      while (cnt_s[s[k]] > cnt_t[s[k]]) {
        cnt_s[s[k]]--;
        k++;
      }
      if (i - k + 1 < len) {
        begin = k;
        len = i - k + 1;
      }
    }
    return len == INT32_MAX ? "" : s.substr(begin, len);
  }
};

int main() {
  io;
  return 0;
}