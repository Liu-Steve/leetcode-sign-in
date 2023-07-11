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
    int maxArea(vector<int> &height)
    {
        auto l = height.begin();
        auto r = height.end() - 1;
        int d = height.size() - 1;
        int res = 0;
        while (d)
        {
            res = max(res, d-- * min(*l, *r));
            *l > *r ? r-- : l++;
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
