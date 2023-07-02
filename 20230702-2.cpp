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
        ListNode *ans = new ListNode(0);
        ListNode *now = ans;
        int rem = 0;
        while (true)
        {
            if (!l1 && !l2)
                break;
            now->next = new ListNode(rem);
            now = now->next;
            if (l1)
            {
                now->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                now->val += l2->val;
                l2 = l2->next;
            }
            if (now->val >= 10)
            {
                now->val -= 10;
                rem = 1;
            }
            else
                rem = 0;
        }
        if (rem)
            now->next = new ListNode(rem);
        return ans->next;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
