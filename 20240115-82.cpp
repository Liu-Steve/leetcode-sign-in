#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p1 = new ListNode(-101);
        ListNode *p2 = p1;
        while (head != nullptr)
        {
            if (head->next != nullptr && head->val == head->next->val)
            {
                int val = head->val;
                while (head != nullptr && head->val == val)
                    head = head->next;
                continue;
            }
            p2->next = head;
            p2 = head;
            head = head->next;
        }
        p2->next = nullptr;
        return p1->next;
    }
};

int main()
{
    io;
    return 0;
}
