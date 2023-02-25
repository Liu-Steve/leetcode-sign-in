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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len = s1.size();
        int l = 0, r = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s1[i] < s2[i])
                l++;
            else if (s1[i] > s2[i])
                r++;
        }
        if ((l + r) & 1)
            return -1;
        return l / 2 + r / 2 + (l & 1) + (r & 1);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}