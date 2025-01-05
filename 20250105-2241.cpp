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

#define MOD 1000000007LL

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

class ATM
{
private:
    vector<long long> cnt;

public:
    ATM() : cnt(5)
    {
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < 5; ++i)
            cnt[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount)
    {
        vector<int> ans(5);
        ans[4] = min(amount / 500ll, cnt[4]);
        amount -= ans[4] * 500;
        ans[3] = min(amount / 200ll, cnt[3]);
        amount -= ans[3] * 200;
        ans[2] = min(amount / 100ll, cnt[2]);
        amount -= ans[2] * 100;
        ans[1] = min(amount / 50ll, cnt[1]);
        amount -= ans[1] * 50;
        ans[0] = min(amount / 20ll, cnt[0]);
        amount -= ans[0] * 20;
        if (amount != 0)
            return vector<int>{-1};
        for (int i = 0; i < 5; ++i)
            cnt[i] -= ans[i];
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
