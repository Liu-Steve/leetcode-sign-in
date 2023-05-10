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
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int r = 1 % k;
        int ans = 1;
        vector<bool> h(k);
        h[r] = true;
        while (r)
        {
            r = r * 10 + 1;
            r %= k;
            if (h[r])
                return -1;
            h[r] = true;
            ans++;
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
