#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret = head;
        ListNode* p1;
        ListNode* p2;
        ListNode* p3;
        ListNode* temp;
        bool end = false;
        for (int i = 0; i < k - 1; ++i) {
            ret = ret->next;
            if (ret == nullptr)
                return head;
        }
        p1 = ret;
        p2 = head;
        temp = ret->next;
        while (!end)
        {
            temp = p1->next;
            for (int i = 0; i < k; ++i) {
                p1 = p1->next;
                if (p1 == nullptr)
                {
                    end = true;
                    p1 = temp;
                    break;
                }
            }
            p3 = p1;
            for(int i = 0; i < k; ++i) {
                temp = p2->next;
                p2->next = p3;
                p3 = p2;
                p2 = temp;
            }
        }
        return ret;
    }
};

int main() {
    io;
    Solution s;
    ListNode* nxt = nullptr;
    ListNode* head;
    for(int i = 10; i > 0; --i) {
        head = new ListNode(i, nxt);
        nxt = head;
    }
    ListNode* arr = s.reverseKGroup(head, 4);
    while (arr)
    {
        cout << arr->val << ' ';
        arr = arr->next;
    }
    return 0;
}