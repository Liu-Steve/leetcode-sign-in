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
    int longestWPI(vector<int> &hours)
    {
        int len = hours.size(), sum = 0;
        stack<pr> st;
        st.emplace(-1, 0);
        for (int i = 0; i < len; ++i)
        {
            hours[i] = (sum += (hours[i] > 8) ? 1 : -1);
            if (hours[i] < st.top().second)
                st.emplace(i, hours[i]);
        }
        int ans = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            if (i == st.top().first)
                st.pop();
            while (hours[i] - st.top().second > 0)
            {
                ans = max(ans, i - st.top().first);
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
    vi v1 = {9, 9, 6, 0, 6, 6, 9};
    cout << s.longestWPI(v1) << endl;
    vi v2 = {6, 6, 6};
    cout << s.longestWPI(v2) << endl;
    vi v3 = {6, 9, 9};
    cout << s.longestWPI(v3) << endl;
    return 0;
}