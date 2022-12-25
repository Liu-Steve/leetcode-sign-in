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

const ll MOD = 1000000007;

class Solution
{
public:
    int countHomogenous(string &s)
    {
        ll res = 0;
        ll cnt = 0;
        char last_ch = ' ';
        for (char ch : s)
        {
            if (last_ch != ch)
            {
                res += cnt * (cnt + 1) / 2;
                res %= MOD;
                last_ch = ch;
                cnt = 0;
            }
            cnt++;
        }
        res += cnt * (cnt + 1) / 2;
        res %= MOD;
        return res;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "abbcccaa";
    cout << s.countHomogenous(s1) << endl;
    string s2 = "xy";
    cout << s.countHomogenous(s2) << endl;
    string s3 = "zzzzz";
    cout << s.countHomogenous(s3) << endl;
    return 0;
}