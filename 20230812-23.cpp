#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct st2
{
    bool operator()(const ListNode *n1, const ListNode *n2) const
    {
        return n1->val > n2->val;
    }
} cmp;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (ListNode *n : lists)
            if (nullptr != n)
                q.emplace(n);
        if (q.empty())
            return nullptr;
        ListNode *ans = q.top();
        ListNode *p = ans;
        q.pop();
        if (p->next != nullptr)
            q.emplace(p->next);
        while (!q.empty())
        {
            p->next = q.top();
            q.pop();
            p = p->next;
            if (p->next != nullptr)
                q.emplace(p->next);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
