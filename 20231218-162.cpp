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

class Solution
{
private:
    int n;
    int sub(vector<int> &nums, int l, int r)
    {
        int m = (l + r) / 2;
        bool gl = ((m == 0) ? true : nums[m] > nums[m - 1]);
        bool gr = ((m == n - 1) ? true : nums[m] > nums[m + 1]);
        if (gl && gr)
            return m;
        else if (gl)
            return sub(nums, m + 1, r);
        else
            return sub(nums, l, m);
    }

public:
    int findPeakElement(vector<int> &nums)
    {
        n = nums.size();
        return sub(nums, 0, n);
    }
};

int main()
{
    io;
    return 0;
}
