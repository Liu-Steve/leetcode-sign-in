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

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> lst;
        while (head)
        {
            lst.emplace_back(head);
            head = head->next;
        }
        int l = 0;
        int r = lst.size() - 1;
        while (l < r)
        {
            lst[l]->next = lst[r];
            lst[r]->next = lst[l + 1];
            l++;
            r--;
        }
        lst[r]->next = nullptr;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
