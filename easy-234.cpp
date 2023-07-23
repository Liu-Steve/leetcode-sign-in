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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        while (head != nullptr)
        {
            list.emplace_back(head->val);
            head = head->next;
        }
        int n = list.size();
        for (int i = 0; i < n - i - 1; ++i)
            if (list[i] != list[n - i - 1])
                return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
