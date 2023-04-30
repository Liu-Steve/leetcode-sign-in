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
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;

        vector<int> res(2);
        res[0] = 2;
        if ((z - y) == 1 && (y - x) == 1) {
            res[0] = 0;
        } else if ((z - y) <= 2 || (y - x) <= 2) {
            res[0] = 1;
        }
        res[1] = (z - x - 2);
        return res;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
