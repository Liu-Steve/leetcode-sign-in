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

const long long MOD = 1000000007LL;

class Solution
{
private:
    int F[30][30][30], G[30][30][30];

public:
    pair<int, int> dp(int n, int f, int s)
    {
        if (F[n][f][s])
            return {F[n][f][s], G[n][f][s]};
        if (f + s == n + 1)
            return {1, 1};
        if (f + s > n + 1)
        {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }
        int earlist = INT_MAX, latest = INT_MIN;
        int n_half = (n + 1) / 2;
        if (s <= n_half)
            for (int i = 0; i < f; ++i)
                for (int j = 0; j < s - f; ++j)
                {
                    auto [x, y] = dp(n_half, i + 1, i + j + 2);
                    earlist = min(earlist, x);
                    latest = max(latest, y);
                }
        else
        {
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i)
                for (int j = 0; j < s_prime - f; ++j)
                {
                    auto [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earlist = min(earlist, x);
                    latest = max(latest, y);
                }
        }
        return {F[n][f][s] = earlist + 1, G[n][f][s] = latest + 1};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));
        if (firstPlayer > secondPlayer)
            swap(firstPlayer, secondPlayer);
        auto [earlist, latest] = dp(n, firstPlayer, secondPlayer);
        return {earlist, latest};
    }
};

int main()
{
    io;
    return 0;
}
