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
public:
    int minDeletion(vector<int> &nums)
    {
        int i = 0;
        int ans = 0;
        int n = nums.size();
        while (i < n - 1)
        {
            if (nums[i] != nums[i + 1]) {
                i += 2;
                continue;
            }
            ans++;
            i++;
        }
        if ((n - ans) % 2 == 1)
            ans++;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
