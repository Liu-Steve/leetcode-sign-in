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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2)
            return waysToBuyPensPencils(total, cost2, cost1);
        long long res = 0;
        for (int i = 0; i * cost1 <= total; ++i)
        {
            int j = (total - i * cost1) / cost2 + 1;
            res += j;
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
