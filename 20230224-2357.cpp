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
    int minimumOperations(vector<int>& nums) {
        hm m;
        for (int n : nums)
            if (!m.count(n) && n)
                m.insert(n);
        return m.size();
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}