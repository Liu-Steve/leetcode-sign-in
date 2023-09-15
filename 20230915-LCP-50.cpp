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
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto &op : operations)
        {
            int sub = gem[op[0]] / 2;
            gem[op[0]] -= sub;
            gem[op[1]] += sub;
        }
        int ming = *min_element(gem.begin(), gem.end());
        int maxg = *max_element(gem.begin(), gem.end());
        return maxg - ming;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
