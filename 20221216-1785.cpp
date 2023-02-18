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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        ll sum = 0;
        for (int n : nums)
            sum += n;
        sum = abs(sum - goal);
        return sum / limit + (sum % limit != 0);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}