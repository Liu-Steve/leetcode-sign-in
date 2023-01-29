#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *nodeA = list1;
        ListNode *nodeB;
        int idx = 0;
        for (int i = 0; i < a - 1; ++i)
            nodeA = nodeA->next;
        nodeB = nodeA;
        for (int i = 0; i < b - a + 2; ++i)
            nodeA = nodeA->next;
        nodeB->next = list2;
        while (list2->next != nullptr)
            list2 = list2->next;
        list2->next = nodeA;
        return list1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}