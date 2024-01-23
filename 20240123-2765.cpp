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
    int alternatingSubarray(vector<int> &nums)
    {
        int target = 1;
        int lst = 1000000009;
        int cur = 1;
        int ans = -1;
        for (int num : nums)
        {
            if (num - lst == target)
            {
                cur += 1;
                target = -target;
                ans = max(ans, cur);
            }
            else
            {
                target = -1 + 2 * (num - lst != 1);
                cur = 1 + (num - lst == 1);
            }
            lst = num;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
