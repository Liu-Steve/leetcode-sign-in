#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
    const long long MOD = 1000000007;

    void mul(long long a[4][4], long long b[4][4])
    {
        long long c[4][4];
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                c[i][j] = 0;
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                for (long long k = 0; k < 4; k++)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                a[i][j] = c[i][j];
    }

    long long pow(long long a[4][4], long long n) {
        long long c[4][4];
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                c[i][j] = (i == j);
        while (n)
        {
            if(n&1)
                mul(c, a);
            mul(a, a);
            n >>= 1;
        }
        return c[3][3];
    }

public:
    int numTilings(int n)
    {
        long long a[4][4] = {
            {0,0,0,1},
            {1,0,1,0},
            {1,1,0,0},
            {1,1,1,1}
        };
        return pow(a, n);
    }
};

int main()
{
    io;
    Solution s;
    cout << s.numTilings(1) << endl;
    return 0;
}