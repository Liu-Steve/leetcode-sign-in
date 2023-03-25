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
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        hm h;
        for (int i = 1; i < n; ++i)
        {
            int sum = nums[i] + nums[i - 1];
            if (h.count(sum))
                return true;
            h.insert(sum);
        }
        return false;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}