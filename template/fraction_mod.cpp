#include <iostream>
const long long C = 998244353;
using namespace std;

//(a^b)%C
long long qpow(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)   ans = (ans * a) % C;
        b >>= 1;
        a = (a * a) % C;
    }
    return ans % C;
}

//(a/b)%C
long long frac_mod(long long a, long long b)
{
    long long ans = a % C;
    ans *= qpow(b, C - 2);
    ans = ans % C;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << frac_mod(1, 1) << endl;
    return 0;
}
