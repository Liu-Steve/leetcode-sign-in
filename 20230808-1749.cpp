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
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int minSum = 0;
        int maxSum = 0;
        int nowSum = 0;
        for (int num : nums)
        {
            nowSum += num;
            minSum = min(minSum, nowSum);
            maxSum = max(maxSum, nowSum);
            ans = max(ans, nowSum - minSum);
            ans = max(ans, maxSum - nowSum);
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
