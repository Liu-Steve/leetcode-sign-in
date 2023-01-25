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
    string getSmallestString(int n, int k)
    {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0; --i)
        {
            if (k <= 25)
            {
                s[i] += k;
                break;
            }
            s[i] = 'z';
            k -= 25;
        }
        return s;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.getSmallestString(3, 27) << endl;
    cout << s.getSmallestString(5, 73) << endl;
    return 0;
}