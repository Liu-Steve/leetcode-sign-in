#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
private:
    void list2vec(vi &lst, ListNode *head)
    {
        while(head)
        {
            lst.emplace_back(head->val);
            head = head->next;
        }
    }

    int getAns(vi &st, int val)
    {
        int len = st.size();
        int l = 0;
        int r = len;
        while(r - l > 1)
        {
            int mid = (l + r) / 2;
            if (st[mid] > val)
                l = mid;
            else
                r = mid;
        }
        st.resize(l + 1);
        st.emplace_back(val);
        return (l > 0 ? st[l] : 0);
    }
    
public:
    vi nextLargerNodes(ListNode *head)
    {
        vi lst;
        list2vec(lst, head);
        int n = lst.size();

        vi ans(n);
        vi st;
        st.emplace_back(INT32_MAX);
        for (int i = n - 1; i >= 0; --i)
            ans[i] = getAns(st, lst[i]);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}