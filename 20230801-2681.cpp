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
typedef unordered_map<int, int> memory;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        ll ans = 0;
        ll sum = 0;
        sort(nums.begin(), nums.end());
        for (ll num : nums)
        {
            ans += (((sum + num) % MOD) * ((num * num) % MOD)) % MOD;
            ans %= MOD;
            sum *= 2;
            sum += num;
            sum %= MOD;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
