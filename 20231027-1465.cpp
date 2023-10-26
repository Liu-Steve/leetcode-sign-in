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
    int maxArea(int h, int w, vi &horizontalCuts, vi &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        ll lh = 0;
        ll lw = 0;
        ll last = 0;
        for (int e : horizontalCuts)
        {
            lh = max(lh, e - last);
            last = e;
        }
        lh = max(lh, h - last);
        last = 0;
        for (int e : verticalCuts)
        {
            lw = max(lw, e - last);
            last = e;
        }
        lw = max(lw, w - last);
        return lh * lw % MOD;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
