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
    int maxValueAfterReverse(vector<int> &nums) {
        int base = 0, d = 0, mx = INT_MIN, mn = INT_MAX, n = nums.size();
        for (int i = 1; i < n; i++) {
            int a = nums[i - 1], b = nums[i];
            base += abs(a - b);
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            d = max(d, max(abs(nums[0] - b) - abs(a - b), // i=0
                           abs(nums[n - 1] - a) - abs(a - b))); // j=n-1
        }
        return base + max(d, 2 * (mx - mn));
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
