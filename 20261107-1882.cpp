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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> empty;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> release;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            empty.emplace(servers[i], i);
        }
        long long tik = 0;
        for (long long i = 0; i < m; ++i) {
            tik = max(tik, i);
            while (!release.empty() && release.top().first <= tik) {
                auto [t, id] = release.top();
                release.pop();
                empty.emplace(servers[id], id);
            }
            if (empty.empty()) {
                tik = release.top().first;
                while (!release.empty() && release.top().first <= tik) {
                    auto [t, id] = release.top();
                    release.pop();
                    empty.emplace(servers[id], id);
                }
            }
            ans.push_back(empty.top().second);
            release.emplace(tik + tasks[i], empty.top().second);
            empty.pop();
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
