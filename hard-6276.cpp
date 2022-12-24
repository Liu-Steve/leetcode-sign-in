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

const ll MOD = 1000000007;

//(a^b)%MOD
long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

//(a/b)%MOD
long long frac_mod(long long a, long long b)
{
    long long ans = a % MOD;
    ans *= qpow(b, MOD - 2);
    ans = ans % MOD;
    return ans;
}

class Solution
{
private:
    unordered_map<ll, ll> jie_cache;
    ll jie(ll n)
    {
        if (jie_cache.find(n) != jie_cache.end())
            return jie_cache[n];
        ll ret = 1;
        for (int i = 1; i <= n; ++i)
        {
            ret *= i;
            ret %= MOD;
        }
        jie_cache.emplace(n, ret);
        return ret;
    }

public:
    int countAnagrams(string &s)
    {
        ll res = 1;
        ll cnt[26];
        ll all = 0;
        memset(cnt, 0, sizeof(cnt));
        s.push_back(' ');
        for (char ch : s)
        {
            if (ch != ' ')
            {
                cnt[ch - 'a']++;
                all++;
                continue;
            }
            res *= jie(all);
            res %= MOD;
            for (int i = 0; i < 26; ++i)
            {
                res *= frac_mod(1, jie(cnt[i]));
                res %= MOD;
            }
            all = 0;
            memset(cnt, 0, sizeof(cnt));
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "too hot";
    cout << s.countAnagrams(s1) << endl;
    string s2 = "aa";
    cout << s.countAnagrams(s2) << endl;
    return 0;
}