#include <bits/stdc++.h>

#include <algorithm>
#include <cstdint>
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

template <typename T, typename Compare = less<T>>
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;
    size_t sz = 0;
    long long s = 0;

    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    long long sum() {
        return s;
    }

    void remove(T x) {
        remove_cnt[x]++;
        sz--;
        s -= x;
    }

    T top() {
        apply_remove();
        return pq.top();
    }

    T pop() {
        apply_remove();
        T x = pq.top();
        pq.pop();
        sz--;
        s -= x;
        return x;
    }

    void push(T x) {
        if (remove_cnt[x] > 0) {
            remove_cnt[x]--;
        } else {
            pq.push(x);
        }
        sz++;
        s += x;
    }

    T push_pop(T x) {
        apply_remove();
        pq.push(x);
        s += x;
        x = pq.top();
        pq.pop();
        s -= x;
        return x;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> dis = medianSlidingWindow(nums, x);
        vector f(k + 1, vector<long long>(n + 1));
        for (int i = 1; i <= k; i++) {
            f[i][i * x - 1] = LLONG_MAX;
            for (int j = i * x; j <= n - (k - i) * x; j++) {
                f[i][j] = min(f[i][j - 1], f[i - 1][j - x] + dis[j - x]);
            }
        }
        return f[k][n];
    }

    vector<long long> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        LazyHeap<int> left;
        LazyHeap<int, greater<>> right;
        for (int i = 0; i < n; i++) {
            int in = nums[i];
            if (left.size() == right.size()) {
                left.push(right.push_pop(in));
            } else {
                right.push(left.push_pop(in));
            }
            int l = i + 1 - k;
            if (l < 0) {
                continue;
            }
            long long v = left.top();
            long long s1 = v * left.size() - left.sum();
            long long s2 = right.sum() - v * right.size();
            ans[l] = s1 + s2;
            int out = nums[l];
            if (out <= left.top()) {
                left.remove(out);
                if (left.size() < right.size()) {
                    left.push(right.pop());
                }
            } else {
                right.remove(out);
                if (left.size() > right.size() + 1) {
                    right.push(left.pop());
                }
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
