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
    int climbStairs(int n) {
        int n1 = 0, n2 = 1, n3 = 1;
        if(n == 0)
            return 1;
        for(int i = 0; i < n; ++i)
        {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
