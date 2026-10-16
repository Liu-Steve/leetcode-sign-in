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

class BIT {
public:
    BIT(int n) {
        size = n;
        _tree1.assign(n + 2, 0);
        _tree2.assign(n + 2, 0);
    }

    void add(int left, int right, int delta) {
        _add(left, delta);
        _add(right + 1, -delta);
    }

    long long query(int left, int right) {
        return _query(right) - _query(left - 1);
    }

private:
    int size;
    vector<long long> _tree1;
    vector<long long> _tree2;

    int _lowbit(int index) {
        return index & -index;
    }

    void _add(int index, int delta) {
        index += 1;
        long long rawIndex = index;
        while (index <= size) {
            _tree1[index] += delta;
            _tree2[index] += rawIndex * delta;
            index += _lowbit(index);
        }
    }

    long long _query(int index) {
        index += 1;
        long long rawIndex = index + 1;
        if (index > size) {
            index = size;
        }
        long long res = 0;
        while (index > 0) {
            res += rawIndex * _tree1[index] - _tree2[index];
            index -= _lowbit(index);
        }
        return res;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        BIT bit(n + 10);
        long long ans = 0;
        long long cur = 0;
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            int j = (seen.count(a) ? seen[a] : -1) + 1;
            long long q = bit.query(j, i);
            cur = (cur + q * 2 + i - j + 1) % MOD;
            ans = (ans + cur) % MOD;
            bit.add(j, i, 1);
            seen[a] = i;
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}