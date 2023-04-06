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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        vector<int> ans(2);
        sort(stones.begin(), stones.end());
        int n = stones.size();

        // max
        ans[1] =
            stones[n - 1] - stones[0] - n + 2 -
            min(stones[1] - stones[0], stones[n - 1] - stones[n - 2]);

        // min
        int l = 0;
        int r = 0;
        int maxcnt = 0;
        bool longest = false;
        for (r = 0; r < n; ++r)
        {
            while (stones[r] - stones[l] + 1 > n)
                l++;
            if (r - l + 1 > maxcnt ||
                r - l + 1 == maxcnt && stones[r] - stones[l] + 1 == n)
            {
                maxcnt = r - l + 1;
                longest = stones[r] - stones[l] + 1 == n;
            }
        }
        if (n - maxcnt == 1 && !longest)
            ans[0] = 2;
        else
            ans[0] = n - maxcnt;

        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {7, 4, 9};
    vi a1 = s.numMovesStonesII(v1);
    cout << a1[0] << ' ' << a1[1] << endl;
    vi v2 = {6, 5, 4, 3, 10};
    vi a2 = s.numMovesStonesII(v2);
    cout << a2[0] << ' ' << a2[1] << endl;
    return 0;
}