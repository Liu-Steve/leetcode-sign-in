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

class Solution {
public:
    int sumSubarrayMins(const vi& arr)
    {
        int n = arr.size(), st_len = 0, ret = 0;
        pr st[n];
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
    return 0;
}
