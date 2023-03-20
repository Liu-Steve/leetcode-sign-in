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
    int numDupDigitsAtMostN(int n)
    {
        stringstream ss;
        ss << n;
        string nstr;
        ss >> nstr;
        int len = nstr.size();

        int sum = 0;
        int addz = 9;
        for (int i = 0; i < len - 1; ++i)
        {
            sum += addz;
            addz *= 9 - i;
        }
        vector<bool> hs(10, false); // has number
        bool n_is_valid = true;
        for (int i = 0; i < len && n_is_valid; ++i)
        {
            int inum = nstr[i] - '0';
            if (hs[inum])
                n_is_valid = false;
            hs[inum] = true;
            if (inum <= (i == 0))
                continue;
            addz = 0;
            for (int j = (i == 0); j < inum; ++j)
                addz += !hs[j];
            for (int j = i + 1; j < len; ++j)
                addz *= 10 - j;
            sum += addz;
        }
        if (n_is_valid)
            sum++;

        return n - sum;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.numDupDigitsAtMostN(1) << endl;
    cout << s.numDupDigitsAtMostN(10) << endl;
    cout << s.numDupDigitsAtMostN(20) << endl;
    cout << s.numDupDigitsAtMostN(100) << endl;
    cout << s.numDupDigitsAtMostN(1000) << endl;
    return 0;
}