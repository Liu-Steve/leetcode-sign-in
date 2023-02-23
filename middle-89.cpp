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
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        for (int i = 0; i < ans.size(); i++)
            ans[i] = i ^ (i >> 1);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = s.grayCode(3);
    for (auto i : v1)
        cout << hex << i << ' ';
    cout << endl;
    return 0;
}