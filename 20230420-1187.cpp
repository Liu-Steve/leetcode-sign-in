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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        const int inf = 0x7ffffffe;
        sort(arr2.begin(), arr2.end());

        function<int(int)> bit_find = [&](int lim)
        {
            if (lim <= arr2[0])
                return -1;
            int l = 0, r = arr2.size();
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (arr2[m] < lim)
                    l = m;
                else
                    r = m;
            }
            return arr2[l];
        };

        memory hs;

        function<int(int, int)> f = [&](int idx, int lim)
        {
            if (idx == -1)
                return 0;
            ll h = idx;
            h <<= 32;
            h |= lim;
            if (hs.count(h))
                return hs[h];
            int ans = inf;
            if (arr1[idx] < lim)
                ans = min(ans, f(idx - 1, arr1[idx]));
            int cg = bit_find(lim);
            if (cg != -1)
                ans = min(ans, f(idx - 1, cg) + 1);
            hs[h] = ans;
            return ans;
        };

        int ans = f(arr1.size() - 1, inf);
        if (ans == inf)
            return -1;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}