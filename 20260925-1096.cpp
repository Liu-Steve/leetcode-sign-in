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
    vector<string> braceExpansionII(string_view expression) {
        int i = 0;
        int len = expression.size();
        function<set<string>()> d = [&]() {
            set<string> ans = {""};
            while (i < len) {
                char ch = expression[i];
                i++;
                if (ch == ',') {
                    ans.merge(d());
                    break;
                } else if (ch == '}')
                    break;
                else if (ch == '{') {
                    auto con = d();
                    set<string> newans;
                    for (auto& str1 : ans)
                        for (auto& str2 : con) newans.insert(str1 + str2);
                    ans = newans;
                } else {
                    set<string> newans;
                    for (auto& str : ans) newans.insert(str + ch);
                    ans = newans;
                }
            }
            return ans;
        };
        auto ans = d();
        return vector(ans.begin(), ans.end());
    }
};

int main() {
    io;
    return 0;
}