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
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    ll maxValue(ll n, ll index, ll maxSum)
    {
        maxSum -= n;
        ll l = index + 1;
        ll r = n - index;
        if (l > r)
            swap(l, r);
        ll th1 = l * l;
        ll th2 = r * r - (r - l) * (r - l + 1) / 2;
        if (maxSum <= th1)
            return sqrt(maxSum) + 1;
        if (maxSum >= th2)
            return (maxSum - th2) / n + r + 1;
        return sqrt(2 * th1 - 2 * l + 0.25 + 2 * maxSum) - l + 1.5;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.maxValue(4, 2, 6) << endl;
    cout << s.maxValue(6, 1, 10) << endl;
    cout << s.maxValue(7, 0, 17) << endl;
    cout << s.maxValue(7, 3, 100) << endl;
    cout << s.maxValue(4, 0, 4) << endl;
    cout << s.maxValue(8, 6, 20) << endl;
    return 0;
}