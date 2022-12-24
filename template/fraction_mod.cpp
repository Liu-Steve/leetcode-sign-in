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

const long long MOD = 998244353;

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

int main()
{
    io;
    return 0;
}
