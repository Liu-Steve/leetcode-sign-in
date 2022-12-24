#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<vector<ll>> vv;

class Solution
{
private:
    ll gbs;
    ll dv1;
    ll dv2;
    ll ucnt1;
    ll ucnt2;
    bool isValid(ll num)
    {
        ll nAB = num / gbs;
        ll nA = num / dv1;
        ll nB = num / dv2;
        ll A = nB - nAB;
        ll B = nA - nAB;
        ll C = num - nAB - A - B;
        return (A + C >= ucnt1) && (B + C >= ucnt2) && (A + B + C >= ucnt1 + ucnt2);
    }

public:
    int minimizeSet(ll divisor1, ll divisor2, ll uniqueCnt1, ll uniqueCnt2)
    {
        gbs = divisor1 * divisor2 / gcd(divisor1, divisor2);
        dv1 = divisor1;
        dv2 = divisor2;
        ucnt1 = uniqueCnt1;
        ucnt2 = uniqueCnt2;
        if (ucnt1 + ucnt2 == 0)
            return 0;
        ll l = 0;
        ll r = INT32_MAX;
        ll m;
        while (l + 1 < r)
        {
            m = (l + r) / 2;
            if (isValid(m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.minimizeSet(2, 7, 1, 3) << endl;
    cout << s.minimizeSet(3, 5, 2, 1) << endl;
    cout << s.minimizeSet(2, 4, 8, 2) << endl;
    cout << s.minimizeSet(2, 4, 0, 0) << endl;
    cout << s.minimizeSet(78789, 42659, 58291, 182389) << endl;
    cout << s.minimizeSet(92761, 48337, 208563424, 9115778) << endl;
    return 0;
}