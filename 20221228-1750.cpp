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
    int minimumLength(string &s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r && s[l] == s[r])
        {
            char ch = s[l];
            while (l <= r && s[l] == ch)
                l++;
            while (l <= r && s[r] == ch)
                r--;
        }
        return r - l + 1;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "ca";
    cout << s.minimumLength(s1) << endl;
    string s2 = "cabaabac";
    cout << s.minimumLength(s2) << endl;
    string s3 = "aabccabba";
    cout << s.minimumLength(s3) << endl;
    string s4 = "abcacba";
    cout << s.minimumLength(s4) << endl;
    string s5 = "aaaaaa";
    cout << s.minimumLength(s5) << endl;
    return 0;
}