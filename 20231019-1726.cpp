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
    int tupleSameProduct(vector<int>& nums) {
        memory mul;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                mul[nums[i] * nums[j]]++;
        int ans = 0;
        for (auto [_, cnt] : mul)
            ans += cnt * (cnt - 1) * 4;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
