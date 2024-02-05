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
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> pq;
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            pq.emplace(dp[i - 1], i - 1);
            while (pq.top().second < i - k)
                pq.pop();
            dp[i] = nums[i] + pq.top().first;
        }
        return dp[n - 1];
    }
};

int main()
{
    io;
    return 0;
}
