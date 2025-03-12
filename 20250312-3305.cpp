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

class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {
        int n = word.size();
        vector<int> a(n + 1);
        vector<int> e(n + 1);
        vector<int> i(n + 1);
        vector<int> o(n + 1);
        vector<int> u(n + 1);
        vector<int> other(n + 1);
        for (int j = 0; j < n; ++j)
        {
            a[j + 1] = a[j];
            e[j + 1] = e[j];
            i[j + 1] = i[j];
            o[j + 1] = o[j];
            u[j + 1] = u[j];
            other[j + 1] = other[j];
            switch (word[j])
            {
            case 'a':
                a[j + 1]++;
                break;
            case 'e':
                e[j + 1]++;
                break;
            case 'i':
                i[j + 1]++;
                break;
            case 'o':
                o[j + 1]++;
                break;
            case 'u':
                u[j + 1]++;
                break;
            default:
                other[j + 1]++;
                break;
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j)
            for (int m = j; m <= n; ++m)
                if (a[m] - a[j] > 0 &&
                    e[m] - e[j] > 0 &&
                    i[m] - i[j] > 0 &&
                    o[m] - o[j] > 0 &&
                    u[m] - u[j] > 0 &&
                    other[m] - other[j] == k)
                    ans++;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
