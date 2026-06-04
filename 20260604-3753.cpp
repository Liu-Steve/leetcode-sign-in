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
    long long calc(long long n) {
        long long ans = 0;
        for (long long pow10 = 1; n >= pow10 * 100; pow10 *= 10) {
            long long max_prefix = n / (pow10 * 1000);
            long long n2 = n / pow10;
            int L = n2 / 100 % 10;
            int M = n2 / 10 % 10;
            int R = n2 % 10;
            long long cnt = max_prefix * 570 - 45;
            cnt += (121 + L * 15 - L * L) * L / 3;
            cnt += (L + M) * max(M - L - 1, 0) / 2;
            cnt += (19 - min(L, M)) * min(L, M) / 2;
            if (L < M) {
                cnt += min(M, R);
            } else if (L > M) {
                cnt += max(R - M - 1, 0);
            }
            ans += cnt * pow10;
            if ((L - M) * (M - R) < 0) {
                long long max_suffix = n % pow10;
                ans += max_suffix + 1;
            }
        }
        return ans;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};

int main() {
    io;
    return 0;
}