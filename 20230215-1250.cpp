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

class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        int g = nums[0];
        if (g == 1)
            return true;
        int len = nums.size();
        for (int i = 1; i < len; ++i)
        {
            g = __gcd(g, nums[i]);
            if (g == 1)
                return true;
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