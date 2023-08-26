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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] <= r)
            {
                r = max(r, intervals[i][1]);
                continue;
            }
            ans.emplace_back(vector<int>{l, r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
        ans.emplace_back(vector<int>{l, r});
        l = intervals[n - 1][0];
        r = intervals[n - 1][1];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
