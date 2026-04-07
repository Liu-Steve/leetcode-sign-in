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

class Robot {
    int w;
    int h;
    int s = 0;

    tuple<int, int, string> getState() {
        if (s < w) {
            return {s, 0, "East"};
        } else if (s < w + h - 1) {
            return {w - 1, s - w + 1, "North"};
        } else if (s < w * 2 + h - 2) {
            return {w * 2 + h - s - 3, h - 1, "West"};
        } else {
            return {0, (w + h) * 2 - s - 4, "South"};
        }
    }

public:
    Robot(int width, int height) : w(width), h(height) {}

    void step(int num) {
        s = (s + num - 1) % ((w + h - 2) * 2) + 1;
    }

    vector<int> getPos() {
        auto [x, y, _] = getState();
        return {x, y};
    }

    string getDir() {
        return get<2>(getState());
    }
};

int main() {
    io;
    return 0;
}