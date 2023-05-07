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
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<long long> mod(60);
        for (int t : time)
            mod[t % 60]++;
        long long ans = mod[0] * (mod[0] - 1) / 2 + mod[30] * (mod[30] - 1) / 2;
        for (int i = 1; i < 30; ++i)
            ans += mod[i] * mod[60 - i];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
