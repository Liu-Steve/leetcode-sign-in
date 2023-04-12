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

class Solution
{
private:
    int solve(string_view text, int add)
    {
        int n = text.size();
        if (n == 0)
            return add;
        int ans = 0;
        int l = 1;
        int r = n - 1;
        while (r - l >= 0)
        {
            bool eq = true;
            for (int i = 0; i < l; ++i)
            {
                if (text[i] != text[r + i])
                {
                    eq = false;
                    break;
                }
            }
            if (eq)
                return solve(text.substr(l, r - l), add + 2);
            l++;
            r--;
        }
        return add + 1;
    }

public:
    int longestDecomposition(string_view text)
    {
        return solve(text, 0);
    }
};

int main()
{
    io;
    Solution s;
    cout << s.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << s.longestDecomposition("merchant") << endl;
    cout << s.longestDecomposition("antaprezatepzapreanta") << endl;
    cout << s.longestDecomposition("abcddabc") << endl;
    return 0;
}