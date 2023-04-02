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

class Solution {
private:
    memory hash;
    vi v;

    inline int f(int l, int r)
    {
        return (l << 6) | r;
    }

    int mem(int l, int r)
    {
        if (r - l <= 1)
            return 0;
        int fval = f(l, r);
        if (hash.count(fval))
            return hash[fval];
        int ans = INT32_MAX;
        for (int i = l + 1; i < r; ++i)
            ans = min(ans, mem(l, i) + mem(i, r) + v[l] * v[r] * v[i]);
        hash[fval] = ans;
        return ans;
    }

public:
    int minScoreTriangulation(vi& values) {
        v = values;
        return mem(0, v.size() - 1);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}