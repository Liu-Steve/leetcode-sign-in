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

class Solution
{
public:
    bool checkPalindromeFormation(string a, string b)
    {
        int len = a.size();
        int flip = 0;
        for (int i = 0; i < len / 2; ++i)
        {
            int j = len - 1 - i;
            if (!flip && a[i] != b[j])
            {
                flip++;
                i--;
            }
            else if (flip && a[i] != a[j])
            {
                flip++;
                break;
            }
        }
        if (flip < 2)
            return true;
        flip = 0;
        for (int i = 0; i < len / 2; ++i)
        {
            int j = len - 1 - i;
            if (!flip && a[i] != b[j])
            {
                flip++;
                i--;
            }
            else if (flip && b[i] != b[j])
            {
                flip++;
                break;
            }
        }
        if (flip < 2)
            return true;
        flip = 0;
        for (int i = 0; i < len / 2; ++i)
        {
            int j = len - 1 - i;
            if (!flip && b[i] != a[j])
            {
                flip++;
                i--;
            }
            else if (flip && a[i] != a[j])
            {
                flip++;
                break;
            }
        }
        if (flip < 2)
            return true;
        flip = 0;
        for (int i = 0; i < len / 2; ++i)
        {
            int j = len - 1 - i;
            if (!flip && b[i] != a[j])
            {
                flip++;
                i--;
            }
            else if (flip && b[i] != b[j])
            {
                flip++;
                break;
            }
        }
        if (flip < 2)
            return true;
        return false;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.checkPalindromeFormation("x", "y") << endl;
    cout << s.checkPalindromeFormation("abdef", "fecab") << endl;
    cout << s.checkPalindromeFormation("ulacfd", "jizalu") << endl;
    cout << s.checkPalindromeFormation("abcdcfg", "gfijklm") << endl;
    cout << s.checkPalindromeFormation("gfijklm", "abcdcfg") << endl;
    return 0;
}