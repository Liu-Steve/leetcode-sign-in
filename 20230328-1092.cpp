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

class Solution
{
public:
    string shortestCommonSupersequence(string_view str1, string_view str2)
    {
        int l1 = str1.size();
        int l2 = str2.size();
        int dp[l1 + 1][l2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < l1; ++i)
            for (int j = 0; j < l2; ++j)
                if (str1[i] == str2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        stringstream ss;
        int i = l1;
        int j = l2;
        while (i > 0 || j > 0)
        {
            if (i == 0)
            {
                ss << str2[j - 1];
                j--;
            }
            else if (j == 0)
            {
                ss << str1[i - 1];
                i--;
            }
            else if (dp[i][j] == dp[i - 1][j])
            {
                ss << str1[i - 1];
                i--;
            }
            else if (dp[i][j] == dp[i][j - 1])
            {
                ss << str2[j - 1];
                j--;
            }
            else 
            {
                ss << str1[i - 1];
                i--;
                j--;
            }
        }
        string a = ss.str();
        reverse(a.begin(), a.end());
        return a;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}