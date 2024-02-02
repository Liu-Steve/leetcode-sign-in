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
public:
    int stoneGameVI(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<int> sum(n);
        iota(sum.begin(), sum.end(), 0);
        sort(sum.begin(), sum.end(), [&](int i1, int i2)
             { return a[i1] + b[i1] > a[i2] + b[i2]; });
        int suma = 0;
        int sumb = 0;
        for (int i = 0; i < n; i += 2)
            suma += a[sum[i]];
        for (int i = 1; i < n; i += 2)
            sumb += b[sum[i]];
        if (suma == sumb)
            return 0;
        return suma > sumb ? 1 : -1;
    }
};

int main()
{
    io;
    return 0;
}
