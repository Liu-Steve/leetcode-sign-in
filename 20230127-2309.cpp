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

class Solution
{
public:
    string greatestLetter(string_view s)
    {
        char ans = 0;
        ll bs = 0; // bitset
        for (char ch : s)
        {
            bs |= 1l << (ch - 'A');
            if (ch >= 'a')
                ch -= 0x20;
            if (ch > ans &&
                bs & (1l << (ch - 'A')) &&
                bs & (1l << (ch - 'A' + 0x20)))
                ans = ch;
        }
        return ans ? string(1, ans) : "";
    }
};

int main()
{
    io;
    Solution s;
    cout << s.greatestLetter("lEeTcOdE") << endl;
    cout << s.greatestLetter("arRAzFif") << endl;
    cout << s.greatestLetter("AbCdEfGhIjK") << endl;
    return 0;
}