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
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int minSubarray(vi &nums, int p)
    {
        int len = nums.size();
        int res = INT32_MAX;
        nums[0] %= p;
        for (int i = 1; i < len; ++i)
        {
            nums[i] += nums[i - 1];
            nums[i] %= p;
        }
        int r = nums[len - 1];
        if (r == 0)
            return 0;
        unordered_map<int, int> last;
        last[0] = -1;
        for (int i = 0; i < len; ++i)
        {
            int nr = nums[i];
            last[nr] = i;
            nr = (nr - r + p) % p;
            if (last.find(nr) != last.end())
                res = min(res, i - last[nr]);
        }
        return res == INT32_MAX || res == len ? -1 : res;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2};
    cout << s.minSubarray(v1, 148) << endl;
    vi v2 = {1, 2, 3};
    cout << s.minSubarray(v2, 7) << endl;
    return 0;
}