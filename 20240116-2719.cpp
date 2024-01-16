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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
private:
    int calc(string &s, int min_sum, int max_sum)
    {
        int n = s.size();
        vv memo(n, vi(min(9 * n, max_sum) + 1, -1));
        function<int(int, int, bool)> dfs = [&](int i, int sum, bool is_limit) -> int
        {
            if (sum > max_sum)
                return 0;
            if (i == n)
                return sum >= min_sum ? 1 : 0;
            if (!is_limit && memo[i][sum] != -1)
                return memo[i][sum];
            int up = is_limit ? s[i] - '0' : 9;
            int res = 0;
            for (int d = 0; d <= up; ++d)
                res = (res + dfs(i + 1, sum + d, is_limit && d == up)) % MOD;
            if (!is_limit)
                memo[i][sum] = res;
            return res;
        };
        return dfs(0, 0, true);
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int ans = calc(num2, min_sum, max_sum) - calc(num1, min_sum, max_sum) + MOD;
        int sum = 0;
        for (char c : num1)
            sum += c - '0';
        ans += min_sum <= sum && sum <= max_sum;
        return ans % MOD;
    }
};

int main()
{
    io;
    return 0;
}
