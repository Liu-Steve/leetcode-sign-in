#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     int numComponents(ListNode *head, vector<int> &nums)
//     {
//         unordered_set<int> s;
//         for (int num : nums)
//         {
//             s.insert(num);
//         }
//         int ret = 0;
//         bool last_in = false;
//         while (head)
//         {
//             if (s.count(head->val))
//             {
//                 if (!last_in)
//                     ret++;
//                 last_in = true;
//             }
//             else
//                 last_in = false;
//             head = head->next;
//         }
//         return ret;
//     }
// };

class Solution
{
public:
    int numComponents(ListNode *head, const vector<int> &nums)
    {
        int s[10001];
        memset(s, 0, sizeof(s));
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            ++s[nums[i]];
        int ret = 0;
        bool last_in = false;
        while (head)
        {
            if (s[head->val])
            {
                if (!last_in)
                    ret++;
                last_in = true;
            }
            else
                last_in = false;
            head = head->next;
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    ListNode *node = nullptr;
    for (int i = 19; i >= 0; --i)
    {
        ListNode *n = new ListNode(i, node);
        node = n;
    }
    vector<int> v1 = {1, 3, 4, 7, 19, 18};
    cout << s.numComponents(node, v1) << endl;

    return 0;
}