#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class Solution {
public:
    int countAsterisks(string &s) {
        bool v = true;
        int cnt = 0;
        for (char ch : s)
        {
            if (ch == '|')
                v = !v;
            else if (v && ch == '*')
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "l|*e*et|c**o|*de|";
    cout << s.countAsterisks(s1) << endl;
    string s2 = "iamprogrammer";
    cout << s.countAsterisks(s2) << endl;
    string s3 = "yo|uar|e**|b|e***au|tifu|l";
    cout << s.countAsterisks(s3) << endl;
    return 0;
}