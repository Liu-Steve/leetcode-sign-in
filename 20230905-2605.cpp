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
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        vector<bool> num(10, false);
        int min1 = 10;
        int min2 = 10;
        int ans = 10;
        for (int n : nums1)
        {
            num[n] = true;
            min1 = min(min1, n);
        }
        for (int n: nums2)
        {
            if (num[n])
                ans = min(ans, n);
            min2 = min(min2, n);
        }
        if (ans < 10)
            return ans;
        if (min1 > min2)
            swap(min1, min2);
        return min1 * 10 + min2;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
