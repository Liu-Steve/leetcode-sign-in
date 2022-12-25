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
    int minimumBoxes(ll n)
    {
        ll i = pow(n * 6, 1.0 / 3);
        ll gi = i * (i + 1) * (i + 2) / 6;
        if (gi > n)
        {
            i--;
            gi = i * (i + 1) * (i + 2) / 6;
        }
        ll j = ceil((sqrt((n - gi) * 8 + 1) - 1) / 2);
        return j + i * (i + 1) / 2;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.minimumBoxes(1) << endl;
    cout << s.minimumBoxes(3) << endl;
    cout << s.minimumBoxes(4) << endl;
    cout << s.minimumBoxes(11) << endl;
    cout << s.minimumBoxes(15) << endl;
    return 0;
}