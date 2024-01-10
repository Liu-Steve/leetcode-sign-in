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

class Solution {
public:
    ll minCost(vi& nums, int x) {
        ll ans = INT64_MAX;
        int n = nums.size();
        vi cost(nums);
        for (ll i = 0; i < n; ++i)
        {
            ll sum = x * i;
            for (int j = 0; j < n; ++j)
            {
                cost[j] = min(cost[j], nums[(j + n - i) % n]);
                sum += cost[j];
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
