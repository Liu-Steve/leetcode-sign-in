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
    int fillCups(vector<int>& amount) {
        int m = 0;
        int s = 0;
        for (int n : amount)
        {
            m = max(m, n);
            s += n;
        }
        s = (s & 1) + (s >> 1);
        return max(m, s);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}