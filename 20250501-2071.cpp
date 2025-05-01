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
#define MAX_N 10000
#define MAX_E 13

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
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        auto m = workers.size();
        auto check = [&](int k) -> bool
        {
            int i = 0;
            int p = pills;
            deque<int> valid_tasks;
            for (int j = m - k; j < m; ++j)
            {
                int w = workers[j];
                while (i < k && tasks[i] <= w + strength)
                {
                    valid_tasks.push_back(tasks[i]);
                    i++;
                }
                if (valid_tasks.empty())
                    return false;
                if (w >= valid_tasks.front())
                {
                    valid_tasks.pop_front();
                    continue;
                }
                if (p == 0)
                    return false;
                p--;
                valid_tasks.pop_back();
            }
            return true;
        };
        int l = 0;
        int r = min(tasks.size(), m) + 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    io;
    return 0;
}
