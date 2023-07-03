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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1;
        stack<int> st2;
        while (l1)
        {
            st1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            st2.emplace(l2->val);
            l2 = l2->next;
        }
        if (st1.size() < st2.size())
            swap(st1, st2);
        ListNode *ans = nullptr;
        while (!st1.empty())
        {
            ListNode *now = new ListNode(st1.top(), ans);
            st1.pop();
            if (ans && ans->val >= 10)
            {
                now->val += 1;
                ans->val -= 10;
            }
            if (!st2.empty())
            {
                now->val += st2.top();
                st2.pop();
            }
            ans = now;
        }
        if (ans->val >= 10)
        {
            ans->val -= 10;
            ans = new ListNode(1, ans);
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
