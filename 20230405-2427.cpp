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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 1;
        for (int i = 1; i <= g / 2; ++i)
            if (a % i == 0 && b % i == 0)
                ans++;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}