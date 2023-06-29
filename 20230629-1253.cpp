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
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        int sum = 0;
        int twocnt = 0;
        for (int c : colsum)
        {
            sum += c;
            twocnt += (c == 2);
        }
        if (sum != upper + lower || twocnt > upper || twocnt > lower)
            return {};
        upper -= twocnt;
        vector<vector<int>> ans(2);
        for (int c : colsum)
        {
            if (c == 0)
            {
                ans[0].emplace_back(0);
                ans[1].emplace_back(0);
            }
            else if (c == 2)
            {
                ans[0].emplace_back(1);
                ans[1].emplace_back(1);
            }
            else if (upper)
            {
                ans[0].emplace_back(1);
                ans[1].emplace_back(0);
                upper--;
            }
            else
            {
                ans[0].emplace_back(0);
                ans[1].emplace_back(1);
            }
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
