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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        int xs = 1;
        while(xs < bound)
        {
            int ys = 1;
            while(xs + ys <= bound)
            {
                ans.emplace(xs + ys);
                if (y == 1)
                    break;
                ys *= y;
            }
            if (x == 1)
                break;
            xs *= x;
        }
        vector<int> anss;
        for (auto v: ans)
            anss.emplace_back(v);
        return anss;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
