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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    bool check(vi &nums, int x, int m)
    {
        ll sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > x)
            {
                cnt++;
                sum = nums[i];
            }
            else
                sum += nums[i];
        }
        return cnt <= m;
    }

    int splitArray(vi &nums, int m)
    {
        ll left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            right += nums[i];
            if (left < nums[i])
                left = nums[i];
        }
        while (left < right)
        {
            ll mid = (left + right) >> 1;
            if (check(nums, mid, m))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    io;
    return 0;
}
