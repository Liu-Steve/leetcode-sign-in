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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<long long> cnt(k);
        set<int> empty;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> running;
        for (int i = 0; i < k; ++i) {
            empty.insert(i);
        }
        for (int i = 0; i < arrival.size(); ++i) {
            long long tik = arrival[i];
            while (!running.empty() && running.top().first <= tik) {
                empty.insert(running.top().second);
                running.pop();
            }
            if (empty.empty()) {
                continue;
            }
            auto it = empty.lower_bound(i % k);
            if (it == empty.end()) {
                it = empty.begin();
            }
            running.emplace(tik + load[i], *it);
            cnt[*it]++;
            empty.erase(it);
        }
        long long target = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
