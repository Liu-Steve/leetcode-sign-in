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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *f = head;
        ListNode *s = head;
        do
        {
            f = f->next;
            if (f == nullptr)
                return nullptr;
            f = f->next;
            if (f == nullptr)
                return nullptr;
            s = s->next;
        } while (f != s);
        f = head;
        while (f != s)
        {
            f = f->next;
            s = s->next;
        }
        return f;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
