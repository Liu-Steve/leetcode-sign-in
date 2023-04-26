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
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        int ans = 0;

        auto f = [&](int len1, int len2){
            int a = 0;
            int b = 0;
            for (int j = len1; j + len2 <= n; ++j)
            {
                b = prefix[j + len2] - prefix[j];
                a = max(a, prefix[j] - prefix[j - len1]);
                ans = max(ans, a + b);
            }
        };

        f(firstLen, secondLen);
        f(secondLen, firstLen);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
