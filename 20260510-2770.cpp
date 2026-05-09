#include <bits/stdc++.h>

#include <map>
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
    int maximumJumps(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        mp[0].push_back(nums[0]);
        int jmp = -1;
        for (int i = 1; i < nums.size(); ++i) {
            jmp = -1;
            for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
                int u_jmp = it->first;
                auto& lst = it->second;
                for (int num : lst) {
                    if (abs(num - nums[i]) <= target) {
                        jmp = u_jmp + 1;
                        break;
                    }
                }
                if (jmp != -1) {
                    break;
                }
            }
            if (jmp != -1) {
                mp[jmp].push_back(nums[i]);
            }
        }
        return jmp;
    }
};

int main() {
    io;
    return 0;
}