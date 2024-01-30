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
    int minimumSeconds(vector<int> &nums)
    {
        map<int, vector<int>> idx;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            idx[nums[i]].push_back(i);
        int ans = INT32_MAX;
        for (auto &[num, p] : idx)
        {
            int k = p.size();
            int cnt = 0;
            for (int i = 0; i < k; ++i)
                cnt = max(cnt, (p[(i + 1) % k] - p[i] + n - 1) % n + 1);
            ans = min(ans, cnt);
        }
        return ans / 2;
    }
};

int main()
{
    io;
    return 0;
}
