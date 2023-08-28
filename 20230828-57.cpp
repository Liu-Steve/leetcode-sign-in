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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (auto &i : intervals)
        {
            if (i[0] > newInterval[1] && newInterval[0] != -1)
            {
                ans.emplace_back(newInterval);
                newInterval[0] = newInterval[1] = -1;
            }
            if (i[1] < newInterval[0] || i[0] > newInterval[1])
            {
                ans.emplace_back(i);
                continue;
            }
            newInterval[0] = min(newInterval[0], i[0]);
            newInterval[1] = max(newInterval[1], i[1]);
        }
        if (newInterval[0] != -1)
            ans.emplace_back(newInterval);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
