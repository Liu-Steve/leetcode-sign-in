#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            m[n]++;
        int ans1 = 0, ans2 = 0;
        for (auto &[_, cnt] : m)
        {
            ans1 += cnt >> 1;
            ans2 += cnt & 1;
        }
        return {ans1, ans2};
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}