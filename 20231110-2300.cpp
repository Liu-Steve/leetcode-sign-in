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
    vi successfulPairs(vi &spells, vi &potions, ll success)
    {
        sort(potions.begin(), potions.end());
        vi ans;
        for (ll s : spells)
        {
            if (s * potions[0] >= success)
            {
                ans.emplace_back(potions.size());
                continue;
            }
            int l = 0;
            int r = potions.size();
            while (l + 1 < r)
            {
                int m = (l + r) / 2;
                if (s * potions[m] >= success)
                    r = m;
                else
                    l = m;
            }
            ans.emplace_back(potions.size() - r);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
