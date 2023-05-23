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
    int largestValsFromLabels(vi &values, vi &labels, int numWanted, int useLimit)
    {
        vp ele;
        int n = values.size();
        for (int i = 0; i < n; ++i)
            ele.emplace_back(values[i], labels[i]);
        sort(ele.begin(), ele.end(), greater<pr>());
        memory m;
        int cnt = 0;
        int i = 0;
        int ans = 0;
        while (cnt < numWanted && i < n)
        {
            if (!m.count(ele[i].second) || m[ele[i].second] < useLimit)
            {
                m[ele[i].second]++;
                ans += ele[i].first;
                cnt++;
            }
            i++;
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
