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

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        int sl = 0;
        int sr = 0;
        int ret = 0x7fffffff;
        for (r = len - 1; r >= 0; --r)
        {
            if (sr >= x)
                break;
            sr += nums[r];
        }
        if (sr < x)
            return -1;
        if (r == -1 && sr == x)
            return len;
        while (1)
        {
            if (sl + sr == x)
                ret = min(ret, l + len - 1 - r);
            ++r;
            if (r == len)
                break;
            sr -= nums[r];
            while (sl + sr < x)
            {
                sl += nums[l];
                ++l;
            }
        }
        return ret == 0x7fffffff ? -1 : ret;
    }
};

int main() {
    io;
    return 0;
}