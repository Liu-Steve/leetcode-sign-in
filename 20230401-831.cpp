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

class Solution {
private:
    inline char tolow(char ch)
    {
        return ch >= 'a' || ch == '.' ? ch : ch + 'a' - 'A';
    }

    string maskEmail(string_view s)
    {
        stringstream ss;
        ss << tolow(s[0]) << "*****";
        int len = s.size();
        int findat = false;
        for (int i = 2; i < len; ++i)
        {
            if (!findat && s[i] != '@')
                continue;
            if (s[i] == '@')
            {
                findat = true;
                ss << tolow(s[i - 1]) << '@';
                continue;
            }
            ss << tolow(s[i]);
        }
        return ss.str();
    }

    string maskPhone(string_view s)
    {
        char q[4];
        int p = 0;
        int cnt = 0;
        for (char ch : s)
        {
            if (ch < '0' || ch > '9')
                continue;
            q[p] = ch;
            p++;
            p %= 4;
            cnt++;
        }
        stringstream ss;
        switch (cnt)
        {
        case 10:
            ss << "***-***-";
            break;

        case 11:
            ss << "+*-***-***-";
            break;

        case 12:
            ss << "+**-***-***-";
            break;

        case 13:
            ss << "+***-***-***-";
            break;
        
        default:
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            ss << q[p];
            p++;
            p %= 4;
        }
        return ss.str();
    }

public:
    string maskPII(string_view s) {
        if (s[0] >= 'A')
            return maskEmail(s);
        else
            return maskPhone(s);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}