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
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector dis(n, vector(n, -1));
        queue<pair<int, int>> dp1, dp2;
        int d = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    dp1.emplace(i, j);
                }
            }
        }
        vector<int> b{0, 1, 0, -1, 0};
        while (!dp1.empty()) {
            d++;
            while (!dp1.empty()) {
                auto [x, y] = dp1.front();
                dp1.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + b[i];
                    int ny = y + b[i + 1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || dis[nx][ny] != -1) {
                        continue;
                    }
                    dis[nx][ny] = d;
                    dp2.emplace(nx, ny);
                }
            }
            swap(dp1, dp2);
        }
        auto cmp = [&](pair<int, int> p1, pair<int, int> p2) -> bool {
            return dis[p1.first][p1.second] < dis[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector vis(n, vector(n, false));
        int ans = dis[0][0];
        q.emplace(0, 0);
        vis[0][0] = true;
        while (!q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + b[i];
                int ny = y + b[i + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny] == true) {
                    continue;
                }
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
            ans = min(ans, dis[x][y]);
            if (x == n - 1 && y == n - 1) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}