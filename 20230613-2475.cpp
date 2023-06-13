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
    int unequalTriplets(vector<int> &nums)
    {
        memory cnt;
        for (int num : nums)
            cnt[num]++;
        int n = nums.size();
        int ans = 0;
        int a = 0;
        for (auto [k, b] : cnt)
        {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
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
