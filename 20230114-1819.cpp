#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        bool has[mx + 1];
        memset(has, 0, sizeof(has));
        for (int x : nums)
        {
            ans += !has[x];
            has[x] = true;
        }
        for (int i = 1; i <= mx / 3; ++i)
        {
            if (has[i])
                continue;
            int g = 0;
            for (int j = i * 2; j <= mx && g != i; j += i)
            {
                if (has[j])
                {
                    g = gcd(g, j);
                }
            }
            if (g == i)
                ans++;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {6, 10, 3};
    cout << s.countDifferentSubsequenceGCDs(v1) << endl;
    vi v2 = {5, 15, 40, 5, 6};
    cout << s.countDifferentSubsequenceGCDs(v2) << endl;
    return 0;
}