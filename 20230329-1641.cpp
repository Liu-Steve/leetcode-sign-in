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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n + 1][5];
        for (int i = 0; i < 5; ++i)
            dp[0][i] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 5; ++j)
                dp[i][j] = j > 0 ? dp[i - 1][j] + dp[i][j - 1] : 1;
        return dp[n][4];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}