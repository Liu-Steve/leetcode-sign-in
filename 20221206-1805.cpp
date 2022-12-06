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
    int numDifferentIntegers(const string &word)
    {
        set<string> s;
        int p = -1;
        int cnt = 0;
        bool begin = false;
        int len = word.size();
        for (int i = 0; i <= len; ++i)
        {
            if (i >= len || word[i] < '0' || word[i] > '9')
            {
                if (cnt > 0)
                {
                    s.insert(word.substr(p, cnt));
                    cnt = 0;
                }
                begin = false;
            }
            else if (!begin)
            {
                if (word[i] != '0')
                {
                    begin = true;
                }
                p = i;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        return s.size();
    }
};

int main()
{
    io;
    Solution s;
    cout << s.numDifferentIntegers("a123bc34d8ef34") << endl;
    cout << s.numDifferentIntegers("leet1234code234") << endl;
    cout << s.numDifferentIntegers("a1b01c001") << endl;
    cout << s.numDifferentIntegers("0a0") << endl;
    return 0;
}