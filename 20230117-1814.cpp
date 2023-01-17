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
private:
    int d(int n)
    {
        int rev = 0;
        int cp = n;
        while (n)
        {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        return rev - cp;
    }

public:
    int countNicePairs(vi &nums)
    {
        int len = nums.size();
        ll res = 0;
        unordered_map<int, ll> u;
        for (int i = 0; i < len; ++i)
            u[d(nums[i])]++;
        for (auto &[k, v] : u)
        {
            res += v * (v - 1) / 2;
            res %= MOD;
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {42, 11, 1, 97};
    cout << s.countNicePairs(v1) << endl;
    vi v2 = {13, 10, 35, 24, 76};
    cout << s.countNicePairs(v2) << endl;
    return 0;
}