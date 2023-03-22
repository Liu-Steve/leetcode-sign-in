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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

typedef struct st1
{
    int s;
    int a;
    st1(int sc, int ag)
    {
        s = sc;
        a = ag;
    }
} player;

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<player> arr;
        for (int i = 0; i < n; ++i)
            arr.emplace_back(scores[i], ages[i]);
        sort(arr.begin(), arr.end(), [](const player &p1, const player &p2){
            if (p1.s != p2.s)
                return p1.s < p2.s;
            return p1.a < p2.a;
        });
        int dp[n];
        for (int i = 0; i < n; ++i)
            dp[i] = arr[i].s;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (arr[j].a <= arr[i].a)
                    dp[i] = max(dp[i], dp[j] + arr[i].s);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}