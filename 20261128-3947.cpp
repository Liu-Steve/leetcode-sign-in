#include <bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt_factor(n + 1);
        int min_price = INT_MAX;
        for (auto& p : items) {
            cnt_factor[p[0]]++;
            min_price = min(min_price, p[1]);
        }
        vector<int> cnt_multi(n + 1);
        map<int, long long> sum_cnt;
        for (auto& p : items) {
            int factor = p[0], price = p[1];
            if (price >= min_price * 2) {
                continue;
            }
            int& cnt = cnt_multi[factor];
            if (cnt == 0) {
                for (int j = factor; j <= n; j += factor) {
                    cnt += cnt_factor[j];
                }
            }
            if (cnt > 1) {
                sum_cnt[price] += cnt - 1;
            }
        }
        int ans = 0;
        for (auto& [price, cnt] : sum_cnt) {
            if (budget < price) {
                break;
            }
            int c = min(cnt, 1LL * budget / price);
            budget -= price * c;
            ans += c * 2;
        }
        return ans + budget / min_price;
    }
};

int main() {
    io;
    return 0;
}
