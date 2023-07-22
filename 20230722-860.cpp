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
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int b5 = 0;
        int b10 = 0;
        int b20 = 0;
        for (int b : bills)
        {
            if (b == 5)
                b5++;
            else if (b == 10)
            {
                if (b5 == 0)
                    return false;
                b10++;
                b5--;
            }
            else if (b == 20)
            {
                if (b10 == 0)
                {
                    if (b5 < 3)
                        return false;
                    b5 -= 3;
                }
                else
                {
                    if (b5 == 0)
                        return false;
                    b5--;
                    b10--;
                }
            }
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
