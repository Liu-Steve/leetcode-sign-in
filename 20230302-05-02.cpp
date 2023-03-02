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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        for (int i = 0; i < 30; ++i)
        {
            num *= 2;
            if (num >= 1)
            {
                num -= 1;
                ans += "1";
                if (num == 0)
                    break;
            }
            else
                ans += "0";
        }
        if (num != 0)
            return "ERROR";
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.printBin(0.625) << endl;
    cout << s.printBin(0.1) << endl;
    return 0;
}