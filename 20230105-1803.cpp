#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution {
public:
    int countPairs(vector<int> &nums, int low, int high) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x: nums) ++cnt[x];
        for (++high; high; high >>= 1, low >>= 1) {
            unordered_map<int, int> nxt;
            for (auto &[x, c] : cnt) {
                if (high & 1 && cnt.count(x ^ (high - 1))) ans += c * cnt[x ^ (high - 1)];
                if (low & 1 && cnt.count(x ^ (low - 1)))   ans -= c * cnt[x ^ (low - 1)];
                nxt[x >> 1] += c;
            }
            cnt = move(nxt);
        }
        return ans / 2;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}