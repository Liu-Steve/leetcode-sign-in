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

class Solution
{
public:
    bool strongPasswordCheckerII(string &password)
    {
        int len = password.size();
        if (len < 8)
            return false;
        const unordered_set<char> sp = {
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        int p = 0;
        char ch = 0;
        for (int i = 0; i < len; ++i)
        {
            if (ch == password[i])
                return false;
            ch = password[i];
            if (ch >= 'a' && ch <= 'z')
                p |= 1;
            if (ch >= 'A' && ch <= 'Z')
                p |= 2;
            if (ch >= '0' && ch <= '9')
                p |= 4;
            if (sp.count(ch))
                p |= 8;
        }
        return p == 15;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "IloveLe3tcode!";
    cout << s.strongPasswordCheckerII(s1) << endl;
    string s2 = "Me+You--IsMyDream";
    cout << s.strongPasswordCheckerII(s2) << endl;
    string s3 = "1aB!";
    cout << s.strongPasswordCheckerII(s3) << endl;
    return 0;
}