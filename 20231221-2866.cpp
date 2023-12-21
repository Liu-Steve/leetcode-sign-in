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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll maximumSumOfHeights(vi &maxHeights)
    {
        int n = maxHeights.size();
        vl suml(n);
        vl sumr(n);
        stack<pr> st;
        for (int i = 0; i < n; ++i)
        {
            ll h = maxHeights[i];
            while (!st.empty() && st.top().first >= h)
                st.pop();
            if (st.empty())
            {
                suml[i] = h * (i + 1);
                st.emplace(h, i);
                continue;
            }
            auto [lh, lp] = st.top();
            suml[i] = suml[lp] + h * (i - lp);
            st.emplace(h, i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            ll h = maxHeights[i];
            while (!st.empty() && st.top().first >= h)
                st.pop();
            if (st.empty())
            {
                sumr[i] = h * (n - i);
                st.emplace(h, i);
                continue;
            }
            auto [lh, lp] = st.top();
            sumr[i] = sumr[lp] + h * (lp - i);
            st.emplace(h, i);
        }
        ll ans = max(suml[n - 1], sumr[0]);
        for (int i = 0; i < n - 1; ++i)
            ans = max(ans, suml[i] + sumr[i + 1]);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
