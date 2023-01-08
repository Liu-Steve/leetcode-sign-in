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
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution {
public:
    int prefixCount(vector<string>& words, string_view pref) {
        int ret = 0;
        int len = pref.size();
        for (string_view w : words)
        {
            if (w.size() < len)
                continue;
            ret += (w.substr(0, len) == pref);
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    vs s1 = {"pay","attention","practice","attend"};
    cout << s.prefixCount(s1, "at") << endl;
    vs s2 = {"leetcode","win","loops","success"};
    cout << s.prefixCount(s2, "code") << endl;
    return 0;
}