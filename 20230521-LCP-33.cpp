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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int storeWater(vector<int> &bucket, vector<int> &vat)
    {
        int mx = 0;
        int len = bucket.size();
        for (int i = 0; i < len; ++i)
            mx = max(mx, vat[i]);
        if (mx == 0)
            return 0;
        int ans = INT32_MAX;
        for (int x = 1; x <= mx && x < ans; ++x)
        {
            int y = 0;
            for (int i = 0; i < len; ++i)
                y += max(0, (vat[i] + x - 1) / x - bucket[i]);
            ans = min(ans, x + y);
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
