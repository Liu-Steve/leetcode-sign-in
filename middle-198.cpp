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
    int rob(vector<int>& nums) {
        int dp1 = 0;
        int dp2 = 0;
        for (int num: nums)
        {
            int new_dp1 = max(dp1, dp2 + num);
            int new_dp2 = max(dp1, dp2);
            dp1 = new_dp1;
            dp2 = new_dp2;
        }
        return max(dp1, dp2);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
