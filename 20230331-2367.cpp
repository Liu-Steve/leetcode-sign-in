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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt[diff];
        int last[diff];
        int ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(last, 0x7f, sizeof(last));
        for (int n : nums)
        {
            int bias = n % diff;
            if (n - last[bias] == diff)
                cnt[bias]++;
            else
                cnt[bias] = 0;
            if (cnt[bias] >= 2)
                ans++;
            last[bias] = n;
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