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

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> w(n);
        int mx = 0;
        for (int i = 0; i < n; ++i)
        {
            mx = max(mx, height[i]);
            w[i] = mx;
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            mx = max(mx, height[i]);
            w[i] = min(w[i], mx);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += w[i] - height[i];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
