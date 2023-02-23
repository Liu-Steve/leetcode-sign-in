#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

// 亦可公式法 i ^ (i >> 1) ^ start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        ans[0] = start;
        for (int r = 0; r < n; r++)
        {
            for (int i = (1 << r) - 1; i >= 0; i--)
                ans[(1 << (r + 1)) - i - 1] = (1 << r) ^ ans[i];
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = s.circularPermutation(3, 2);
    for (auto i : v1)
        cout << hex << i << ' ';
    cout << endl;
    return 0;
}