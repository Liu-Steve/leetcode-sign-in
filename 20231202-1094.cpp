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
    bool carPooling(vv &trips, int capacity)
    {
        sort(trips.begin(), trips.end(), [](vi &t1, vi &t2)
             { return t1[1] < t2[1]; });
        int cnt = 0;
        priority_queue<pr, vp, greater<pr>> pq; // to, num
        pq.emplace(1001, 0);
        for (vi &t : trips)
        {
            while (pq.top().first <= t[1])
            {
                cnt -= pq.top().second;
                pq.pop();
            }
            cnt += t[0];
            if (cnt > capacity)
                return false;
            pq.emplace(t[2], t[0]);
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
