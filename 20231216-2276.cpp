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

class CountIntervals
{
private:
    map<int, int> m;
    int cnt = 0;

public:
    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        for (auto it = m.lower_bound(left); it != m.end() && it->second <= right; m.erase(it++))
        {
            int l = it->second;
            int r = it->first;
            left = min(left, l);
            right = max(right, r);
            cnt -= r - l + 1;
        }
        cnt += right - left + 1;
        m[right] = left;
    }

    int count()
    {
        return cnt;
    }
};

int main()
{
    io;
    return 0;
}
