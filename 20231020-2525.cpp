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

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        vector<string> ret = {"Neither", "Heavy", "Bulky", "Both"};
        int ans = ((length >= 10000) || (width >= 10000) || (height >= 10000) ||
                   ((long long)length * width * height >= 1000000000)) *
                      2 +
                  (mass >= 100);
        return ret[ans];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
