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
    int countTriplets(vector<int> &nums)
    {
        int len = nums.size();
        int hmp[1 << 16];
        memset(hmp, 0, sizeof(hmp));
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                hmp[nums[i] & nums[j]]++;
        int ans = 0;
        for (int n : nums)
        {
            n ^= 0xffff;
            int s = n;
            do
            {
                ans += hmp[s];
                s = (s - 1) & n;
            } while (s != n);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {2, 1, 3};
    cout << s.countTriplets(v1) << endl;
    vi v2 = {0, 0, 0};
    cout << s.countTriplets(v2) << endl;
    return 0;
}