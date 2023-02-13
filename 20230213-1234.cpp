#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
private:
    int ch2int(char ch)
    {
        int ans = 0;
        switch (ch)
        {
        case 'Q':
            ans = 0;
            break;
        case 'W':
            ans = 1;
            break;
        case 'E':
            ans = 2;
            break;
        case 'R':
            ans = 3;
            break;
        default:
            break;
        }
        return ans;
    }

public:
    int balancedString(string_view s)
    {
        int n = s.size();
        int lim[4];
        memset(lim, 0, sizeof(lim));
        // count
        for (char ch : s)
            lim[ch2int(ch)]++;
        for (int i = 0; i < 4; ++i)
            lim[i] = max(lim[i] - (n >> 2), 0);
        if (!(lim[0] | lim[1] | lim[2] | lim[3]))
            return 0;
        // queue
        int l, r, ans, now[4];
        l = r = 0;
        ans = INT32_MAX;
        memset(now, 0, sizeof(now));
        for (; r < n; r++)
        {
            now[ch2int(s[r])]++;
            while (lim[ch2int(s[l])] < now[ch2int(s[l])])
            {
                now[ch2int(s[l])]--;
                l++;
            }
            bool ok = true;
            for (int i = 0; i < 4; i++)
                if (lim[i] > now[i])
                    ok = false;
            if (ok)
                ans = min(ans, r - l + 1);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.balancedString("QWER") << endl;
    cout << s.balancedString("QQWE") << endl;
    cout << s.balancedString("QQQW") << endl;
    cout << s.balancedString("QQQQ") << endl;
    cout << s.balancedString("QWRQWEEQ") << endl;
    return 0;
}