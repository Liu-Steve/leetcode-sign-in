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

typedef struct st1
{
    bool operator()(const pr &p1, const pr &p2) const
    {
        return p1.second - p1.first < p2.second - p2.first;
    }
} cmp;

class Solution
{
public:
    int findMaxValueOfEquation(vv &points, int k)
    {
        priority_queue<pr, vp, cmp> q;
        int ans = INT32_MIN;
        for (auto &p : points)
        {
            pr p2 = {p[0], p[1]};
            while (!q.empty() && q.top().first < p2.first - k)
                q.pop();
            if (!q.empty())
            {
                const pr &p1 = q.top();
                ans = max(ans, p1.second - p1.first + p2.first + p2.second);
            }
            q.emplace(p2);
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
