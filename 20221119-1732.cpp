#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution {
public:
    int largestAltitude(const vector<int>& gain) {
        int al = 0;
        int m = 0;
        int len = gain.size();
        for (int i = 0; i < len; ++i) {
            al += gain[i];
            m = max(m, al);
        }
        return m;
    }
};

int main() {
    io;
    Solution s;
    vi v1 = {-5,1,5,0,-7};
    vi v2 = {-4,-3,-2,-1,4,3,2};
    cout << s.largestAltitude(v1) << endl;
    cout << s.largestAltitude(v2) << endl;
    return 0;
}