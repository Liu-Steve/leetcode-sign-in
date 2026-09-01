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
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector idx(m, vector<int>(n));
        int cnt_l = 0, sx = 0, sy = 0;
        for (int i = 0; i < m; i++) {
            auto& row = classroom[i];
            for (int j = 0; j < n; j++) {
                char b = row[j];
                if (b == 'L') {
                    idx[i][j] = 1 << cnt_l++;
                } else if (b == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        int u = 1 << cnt_l;
        vector max_energy(m, vector(n, vector<int8_t>(u, -1)));
        max_energy[sx][sy][0] = energy;
        struct Node {
            int x, y, e, mask;
        };
        vector<Node> q = {{sx, sy, energy, 0}}, tmp;
        for (int ans = 0; !q.empty(); ans++) {
            swap(q, tmp);
            while (!tmp.empty()) {
                auto [x, y, e, mask] = tmp.back();
                tmp.pop_back();
                if (mask == u - 1) {
                    return ans;
                }
                if (e == 0) {
                    continue;
                }
                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && classroom[nx][ny] != 'X') {
                        int new_e = classroom[nx][ny] == 'R' ? energy : e - 1;
                        int new_mask = mask | idx[nx][ny];
                        if (new_e > max_energy[nx][ny][new_mask]) {
                            max_energy[nx][ny][new_mask] = new_e;
                            q.emplace_back(nx, ny, new_e, new_mask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    io;
    return 0;
}