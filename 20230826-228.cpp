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
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        long long lst = nums[0];
        long long bgn = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] - lst == 1)
            {
                lst = nums[i];
                continue;
            }
            string nxt = "";
            nxt.append(to_string(bgn));
            if (lst > bgn)
                nxt.append("->" + to_string(lst));
            ans.emplace_back(nxt);
            bgn = lst = nums[i];
        }
        string nxt = "";
        nxt.append(to_string(bgn));
        if (lst > bgn)
            nxt.append("->" + to_string(lst));
        ans.emplace_back(nxt);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
