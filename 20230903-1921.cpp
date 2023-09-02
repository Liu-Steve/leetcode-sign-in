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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for (int i = 0; i < n; ++i)
            dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0);
        sort(dist.begin(), dist.end());
        for (int i = 0; i < n; ++i)
            if (dist[i] <= i)
                return i;
        return n;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
