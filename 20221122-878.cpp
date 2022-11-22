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

const int MOD = 1000000007;

class Solution
{
private:
    int gcd(int a, int b)
    {
        while (min(a, b) > 0)
        {
            if (a > b)
                a = a % b;
            else 
                b = b % a;
        }
        return max(a, b);
    }

public:
    int nthMagicalNumber(int n, int a, int b)
    {
        if (a > b)
            swap(a, b);
        ll g = gcd(a, b);
        ll r = a / g + b / g - 1;
        ll res = (a * b / g * (n / r)) % MOD;
        int idx = n % r;
        int add_a = 0;
        int add_b = b;
        while (idx--)
        {
            if (add_a <= add_b)
                add_a += a;
            else
                add_b += b;
        }
        res += min(add_a, add_b);
        res %= MOD;
        return (int)res;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.nthMagicalNumber(1, 2, 3) << endl;
    cout << s.nthMagicalNumber(4, 2, 3) << endl;
    cout << s.nthMagicalNumber(6, 3, 6) << endl;
    cout << s.nthMagicalNumber(6, 15, 11) << endl;
    return 0;
}