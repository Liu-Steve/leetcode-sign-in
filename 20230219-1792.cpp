#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

inline double d(ll a, ll b)
{
    double ans = b - a;
    ans /= b * (b + 1);
    return ans;
}

class Solution
{
public:
    double maxAverageRatio(vv &classes, int extra)
    {
        priority_queue<pr> heap;
        int len = classes.size();
        for (int i = 0; i < len; ++i)
            heap.emplace(d(classes[i][0], classes[i][1]), i);
        while (extra--)
        {
            int i = heap.top().second;
            heap.pop();
            classes[i][0]++;
            classes[i][1]++;
            heap.emplace(d(classes[i][0], classes[i][1]), i);
        }
        double ans = 0;
        for (vi &v : classes)
            ans += v[0] / (double)v[1];
        ans /= len;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}