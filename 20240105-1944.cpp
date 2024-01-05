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
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        vector<int> stk;
        vector<int> ans(heights.size());
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            int h = heights[i];
            while (!stk.empty() && stk.back() < h)
            {
                stk.pop_back();
                ans[i]++;
            }
            ans[i] += !stk.empty();
            stk.push_back(h);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
