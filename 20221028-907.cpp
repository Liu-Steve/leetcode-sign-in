#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef pair<int, int> p;
const int MOD = 1000000007;

class Solution {
public:
    int sumSubarrayMins(const vector<int>& arr)
    {
        int n = arr.size(), st_len = 0, ret = 0;
        p st[n];
        int dp[n];
        for (int i = 0; i < n; ++i) {
            int j;
            while (st_len && st[st_len - 1].first > arr[i])
                st_len--;
            if (!st_len) {
                j = -1;
                dp[i] = arr[i] * (i - j);
            } else {
                j = st[st_len - 1].second;
                dp[i] = arr[i] * (i - j) + dp[j];
            }
            st[st_len].first = arr[i];
            st[st_len].second = i;
            st_len++;
            ret += dp[i];
            ret %= MOD;
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    vector<int> arr = {11,81,94,43,3};
    cout << s.sumSubarrayMins(arr) << endl;
    return 0;
}