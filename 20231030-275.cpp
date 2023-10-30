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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (citations[m] >= n - m)
                r = m - 1;
            else
                l = m + 1;
        }
        return n - l;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
