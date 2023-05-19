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
    int numTilePossibilities(string &tiles)
    {
        int n = tiles.size();

        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        auto comb = [&](int n, int m)
        {
            return fact[n] / fact[m] / fact[n - m];
        };

        unordered_map<char, int> cnt;
        for (char ch : tiles)
            cnt[ch]++;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (auto &[c, v] : cnt)
            for (int j = n; j >= 0; --j)
            {
                int sum = 0;
                for (int k = 0; k <= v && k <= j; ++k)
                    sum += dp[j - k] * comb(j, k);
                dp[j] = sum;
            }
        
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += dp[i];
        return sum;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
