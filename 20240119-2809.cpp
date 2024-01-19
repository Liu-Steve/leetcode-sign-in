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
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x)
    {
        int n = nums1.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i1, int i2)
             { return nums2[i1] < nums2[i2]; });

        vector<int> f(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int a = nums1[ids[i]], b = nums2[ids[i]];
            for (int j = i + 1; j > 0; --j)
                f[j] = max(f[j], f[j - 1] + a + b * j);
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int t = 0; t <= n; ++t)
            if (s1 + s2 * t - f[t] <= x)
                return t;
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
