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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int n = nums.size();
        int ans = 0, i = 0;
        while (i < n) {
            if (nums[i] > threshold || nums[i] % 2) {
                i++;
                continue;
            }
            int start = i;
            i++;
            while (i < n && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2)
                i++;
            ans = max(ans, i - start);
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
