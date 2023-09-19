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

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int m = (l + r) / 2;
            int nk = 0;
            bool canRob = true;
            for (int num : nums)
            {
                if (!canRob || num > m)
                {
                    canRob = true;
                    continue;
                }
                canRob = false;
                nk++;
            }
            if (nk < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
