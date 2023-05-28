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
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for (int n : nums)
            if (n % 6 == 0)
            {
                sum += n;
                cnt++;
            }
        if (cnt == 0)
            return 0;
        return sum / cnt;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
