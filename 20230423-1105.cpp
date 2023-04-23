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
typedef unordered_map<ll, int> memory;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int mh = 0;
            int len = 0;
            dp[i] = INT32_MAX;
            for (int j = i - 1; j >= 0 && len + books[j][0] <= shelfWidth; --j)
            {
                mh = max(mh, books[j][1]);
                len += books[j][0];
                dp[i] = min(dp[i], dp[j] + mh);
            }
        }
        return dp[n];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}