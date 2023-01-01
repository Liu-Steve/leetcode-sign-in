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
typedef pair<int, int> pr;

class Solution {
public:
    char repeatedCharacter(string_view s) {
        bool cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char ch : s)
        {
            if (cnt[ch - 'a'])
                return ch;
            cnt[ch - 'a'] = true;
        }
        return 'a';
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "abccbaacz";
    cout << s.repeatedCharacter(s1) << endl;
    return 0;
}