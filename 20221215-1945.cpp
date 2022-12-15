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
    int getLucky(string s, int k)
    {
        int res = 0;
        for (char ch : s)
        {
            int num = ch - 'a' + 1;
            res += (num / 10) + (num % 10);
        }
        int res2 = 0;
        k--;
        while (k--)
        {
            while (res)
            {
                res2 += res % 10;
                res /= 10;
            }
            swap(res, res2);
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "iiii";
    cout << s.getLucky(s1, 1) << endl;
    string s2 = "leetcode";
    cout << s.getLucky(s2, 2) << endl;
    return 0;
}