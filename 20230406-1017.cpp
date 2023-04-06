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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0)
            return "0";
        stringstream ss;
        n = -n;
        while(n)
        {
            ss << (n & 1);
            n = -(n >> 1) - (n & 1);
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.baseNeg2(0) << endl;
    cout << s.baseNeg2(2) << endl;
    cout << s.baseNeg2(3) << endl;
    cout << s.baseNeg2(4) << endl;
    return 0;
}