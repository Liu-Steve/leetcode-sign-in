#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int len = nums.size(), sum = 0;
        stack<int> st;
        st.emplace(0);
        for (int i = 1; i < len; ++i)
            if (nums[i] < nums[st.top()])
                st.emplace(i);
        int ans = 0;
        for (int i = len - 1; i >= 1; --i)
        {
            while (i <= st.top() || nums[i] - nums[st.top()] >= 0)
            {
                ans = max(ans, i - st.top());
                st.pop();
                if (st.empty())
                    return ans;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {6, 0, 8, 2, 1, 5};
    cout << s.maxWidthRamp(v1) << endl;
    vi v2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << s.maxWidthRamp(v2) << endl;
    return 0;
}