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
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0;
        int b = 0;
        int c = 0;
        int n = cost.size();
        for (int i = 2; i < n; ++i)
        {
            c = min(a + cost[i - 2], b + cost[i - 1]);
            a = b;
            b = c;
        }
        return min(a + cost[n - 2], b + cost[n - 1]);
    }
};

int main()
{
    io;
    return 0;
}
