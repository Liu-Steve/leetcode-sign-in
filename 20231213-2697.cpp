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

class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        for (; i < j; ++i, --j)
        {
            char newc = min(s[i], s[j]);
            s[i] = newc;
            s[j] = newc;
        }
        return s;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
