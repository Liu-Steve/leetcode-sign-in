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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll minimumPerimeter(ll neededApples)
    {
        ll l = 0;
        ll r = 100000;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            ll apples = m * (2 * m + 1) * (2 * m + 2);
            if (apples == neededApples)
                return 8 * m;
            else if (apples < neededApples)
                l = m;
            else
                r = m;
        }
        return 8 * r;
    }
};

int main()
{
    io;
    return 0;
}
