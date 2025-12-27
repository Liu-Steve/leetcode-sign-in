#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> cnt(n);
        priority_queue<int, vector<int>, greater<int>> room;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> release;
        for (int i = 0; i < n; ++i)
            room.push(i);
        sort(meetings.begin(), meetings.end());
        for (auto &m : meetings)
        {
            while (!release.empty() && release.top().first <= m[0])
            {
                room.push(release.top().second);
                release.pop();
            }
            if (!room.empty())
            {
                release.emplace(m[1], room.top());
                cnt[room.top()]++;
                room.pop();
                continue;
            }
            pair<long long, int> r = release.top();
            release.pop();
            cnt[r.second]++;
            release.emplace(m[1] + r.first - m[0], r.second);
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

int main()
{
    io;
    return 0;
}
