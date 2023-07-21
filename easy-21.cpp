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
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;
        ListNode *ans = nullptr;
        ListNode *p = nullptr;
        if (pHead1->val < pHead2->val)
        {
            ans = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            ans = pHead2;
            pHead2 = pHead2->next;
        }
        p = ans;
        while (pHead1 != nullptr || pHead2 != nullptr)
        {
            if (pHead1 == nullptr)
            {
                p->next = pHead2;
                break;
            }
            if (pHead2 == nullptr)
            {
                p->next = pHead1;
                break;
            }
            if (pHead1->val < pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
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
