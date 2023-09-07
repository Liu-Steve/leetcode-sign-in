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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll repairCars(vi &ranks, int cars)
    {
        auto check = [=](ll m) {
            ll cnt = 0;
            for (int rk : ranks)
                cnt += sqrt(m / rk);
            return cnt >= cars;
        };
        ll l = 0;
        ll r = 1ll * ranks[0] * cars * cars;
        while (l < r)
        {
            ll m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
