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
    int reinitializePermutation(int n)
    {
        int ret = 0;
        int op = 1;
        while (1)
        {
            op = ((op & 1) ? (((op - 1) >> 1) + (n >> 1)) : (op >> 1));
            ret++;
            if (op == 1)
                break;
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    for (int i = 2; i <= 100; i += 2)
        cout << i << '\t' << s.reinitializePermutation(i) << endl;
    return 0;
}