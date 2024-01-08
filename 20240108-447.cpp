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
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        int n = points.size();
        for (auto &p1 : points)
        {
            multiset<int> d;
            for (auto &p2 : points)
            {
                int dis = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                int cnt = d.count(dis);
                ans += cnt * 2;
                d.emplace(dis);
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
