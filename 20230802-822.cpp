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
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        hm f;
        int n = fronts.size();
        for (int i = 0; i < n; ++i)
            if (fronts[i] == backs[i])
                f.emplace(fronts[i]);
        int ans = INT32_MAX;
        for (int num : fronts)
            if (f.find(num) == f.end())
                ans = min(ans, num);
        for (int num : backs)
            if (f.find(num) == f.end())
                ans = min(ans, num);
        if (ans == INT32_MAX)
            return 0;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
