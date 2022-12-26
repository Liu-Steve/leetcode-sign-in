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

class Solution
{
public:
    int minimumMoves(string &s)
    {
        int len = s.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'X')
            {
                i += 2;
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "XXX";
    cout << s.minimumMoves(s1) << endl;
    string s2 = "XXOX";
    cout << s.minimumMoves(s2) << endl;
    string s3 = "OOOOO";
    cout << s.minimumMoves(s3) << endl;
    string s4 = "OXOX";
    cout << s.minimumMoves(s4) << endl;
    return 0;
}