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
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int len = reservedSeats.size();
        sort(reservedSeats.begin(), reservedSeats.end());
        int lst = 0;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int line = reservedSeats[i][0];
            ans += (line - lst - 1) * 2;
            vector<int> seat(11);
            while (i < len && reservedSeats[i][0] == line) {
                seat[reservedSeats[i][1]] = 1;
                i++;
            }
            i--;
            lst = line;
            int sum1 = seat[2] + seat[3] + seat[4] + seat[5];
            int sum2 = seat[4] + seat[5] + seat[6] + seat[7];
            int sum3 = seat[6] + seat[7] + seat[8] + seat[9];
            if (sum1 == 0 && sum3 == 0) {
                ans += 2;
            } else {
                ans += (sum1 == 0 || sum2 == 0 || sum3 == 0);
            }
        }
        ans += (n - lst) * 2;
        return ans;
    }
};

int main() {
    io;
    return 0;
}