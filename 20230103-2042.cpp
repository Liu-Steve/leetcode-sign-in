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
    bool areNumbersAscending(string_view s) {
        string_view last = "0";
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
                continue;
            int cnt = 1;
            while (i + cnt < len && s[i + cnt] != ' ')
                cnt++;
            string_view now = s.substr(i, cnt);
            i += cnt;
            if (last.size() > now.size())
                return false;
            else if (last.size() == now.size() && last >= now)
                return false;
            last = now;
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    cout << s.areNumbersAscending(s1) << endl;
    string s2 = "hello world 5 x 5";
    cout << s.areNumbersAscending(s2) << endl;
    string s3 = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
    cout << s.areNumbersAscending(s3) << endl;
    string s4 = "4 5 11 26";
    cout << s.areNumbersAscending(s4) << endl;
    return 0;
}