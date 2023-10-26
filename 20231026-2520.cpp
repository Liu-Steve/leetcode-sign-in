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
    int countDigits(int num) {
        int rem = num;
        int ans = 0;
        while (rem)
        {
            int n = rem % 10;
            rem /= 10;
            ans += (num % n == 0);
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
