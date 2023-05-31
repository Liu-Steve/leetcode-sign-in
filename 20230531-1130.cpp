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

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        stack<int> st;
        int ans = 0;
        for (int x : arr)
        {
            while (!st.empty() && st.top() <= x)
            {
                int y = st.top();
                st.pop();
                if (st.empty() || st.top() > x)
                    ans += x * y;
                else
                    ans += st.top() * y;
            }
            st.emplace(x);
        }
        while (st.size() >= 2)
        {
            int x = st.top();
            st.pop();
            ans += x * st.top();
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
