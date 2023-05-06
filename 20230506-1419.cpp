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

class Solution {
public:
    int minNumberOfFrogs(string &croakOfFrogs) {
        vector<int> dp(5);
        int ans = 0;
        for (char ch : croakOfFrogs)
        {
            switch (ch)
            {
            case 'c':
                dp[0]++;
                ans = max(ans, dp[0]);
                break;
            case 'r':
                if (dp[1] >= dp[0])
                    return -1;
                dp[1] += 1;
                break;
            case 'o':
                if (dp[2] >= dp[1])
                    return -1;
                dp[2] += 1;
                break;
            case 'a':
                if (dp[3] >= dp[2])
                    return -1;
                dp[3] += 1;
                break;
            case 'k':
                if (dp[4] >= dp[3])
                    return -1;
                dp[3]--;
                dp[2]--;
                dp[1]--;
                dp[0]--;
                break;
            default:
                break;
            }
        }
        if (dp[0] == 0)
            return ans;
        else
            return -1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
