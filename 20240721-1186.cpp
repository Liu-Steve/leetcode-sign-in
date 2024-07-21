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
    int maximumSum(vector<int> &arr)
    {
        int dp[2] = {arr[0], 0};
        int res = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            dp[1] = max(dp[0], dp[1] + arr[i]);
            dp[0] = max(dp[0], 0) + arr[i];
            res = max(res, max(dp[0], dp[1]));
        }
        return res;
    }
};

int main()
{
    io;
    return 0;
}
