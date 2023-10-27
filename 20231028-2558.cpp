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

class Solution {
public:
    ll pickGifts(vi& gifts, int k) {
        ll sum = 0;
        priority_queue<int> pq;
        for (int g : gifts)
        {
            sum += g;
            pq.emplace(g);
        }
        while (k--)
        {
            int tp = pq.top();
            int ntp = sqrt(tp);
            sum -= tp - ntp;
            pq.pop();
            pq.emplace(ntp);
        }
        return sum;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
