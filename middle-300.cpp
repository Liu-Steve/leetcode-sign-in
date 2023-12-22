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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> g;
        for (int num : nums)
        {
            auto it = lower_bound(g.begin(), g.end(), num);
            if (it == g.end())
                g.push_back(num);
            else
                *it = num;
        }
        return g.size();
    }
};

int main()
{
    io;
    return 0;
}
