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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

inline int h(int l, int r)
{
    return (l << 5) | r;
}

class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1))
            return -1;
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + stones[i];

        memory m;
        function<int(int, int)> f = [&](int l, int r)
        {
            if (l == r)
                return 0;
            int hs = h(l, r);
            if (m.count(hs))
                return m[hs];
            int minv = INT32_MAX;
            for (int p = l; p < r; p += k - 1)
                minv = min(minv, f(l, p) + f(p + 1, r));
            if ((r - l) % (k - 1) == 0)
                minv += sum[r + 1] - sum[l];
            m[hs] = minv;
            return minv;
        };

        int ans = f(0, n - 1);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {3, 5, 1, 2, 6};
    cout << s.mergeStones(v1, 3) << endl;
    return 0;
}