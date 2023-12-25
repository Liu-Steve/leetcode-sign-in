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
    vector<int> numOfBurgers(int a, int b) {
        if (a & 1 == 1)
            return {};
        vector<int> ans = {a / 2 - b, 2 * b - a / 2};
        if (ans[0] < 0 || ans[1] < 0)
            return {};
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
