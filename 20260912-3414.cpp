#include <bits/stdc++.h>

#include <vector>
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
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct tuple {
            int l, r, weight, i;
        };
        vector<tuple> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(a.begin(), a.end(), [](tuple t1, tuple t2) {
            return t1.r < t2.r;
        });
        vector<array<pair<long long, vector<int>>, 5>> f(n + 1);
        for (int i = 0; i < n; i++) {
            auto [l, r, weight, idx] = a[i];
            int k = lower_bound(a.begin(), a.begin() + i, l,
                                [](tuple& t, int val) {
                                    return t.r < val;
                                }) -
                    a.begin();
            for (int j = 1; j < 5; j++) {
                long long s1 = f[i][j].first;
                long long s2 = f[k][j - 1].first + weight;
                if (s1 > s2) {
                    f[i + 1][j] = f[i][j];
                    continue;
                }
                vector<int> new_id = f[k][j - 1].second;
                new_id.push_back(idx);
                sort(new_id.begin(), new_id.end());
                if (s1 == s2 && f[i][j].second < new_id) {
                    new_id = f[i][j].second;
                }
                f[i + 1][j] = {s2, new_id};
            }
        }
        return f[n][4].second;
    }
};

int main() {
    io;
    return 0;
}