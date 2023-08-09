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
    int subtractProductAndSum(int n) {
        int t = 1;
        int s = 0;
        while (n)
        {
            t *= n % 10;
            s += n % 10;
            n /= 10;
        }
        return t - s;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
