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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int b1 = prices[0];
        int b = 0;
        vector<int> benifit(n);
        for (int i = 0; i < n; ++i)
        {
            b = benifit[i] = max(b, prices[i] - b1);
            b1 = min(b1, prices[i]);
        }
        int ans = 0;
        b1 = prices[n - 1];
        for (int i = n - 1; i >= 0; --i)
        {
            ans = max(ans, benifit[i] + b1 - prices[i]);
            b1 = max(b1, prices[i]);
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
