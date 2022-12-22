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
    int finalValueAfterOperations(vector<string> &operations)
    {
        int n = operations.size();
        int x = 0;
        for (int i = 0; i < n; ++i)
            x += operations[i][1] == '+' ? 1 : -1;
        return x;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"--X", "X++", "X++"};
    cout << s.finalValueAfterOperations(v1) << endl;
    vs v2 = {"++X", "++X", "X++"};
    cout << s.finalValueAfterOperations(v2) << endl;
    vs v3 = {"X++", "++X", "--X", "X--"};
    cout << s.finalValueAfterOperations(v3) << endl;
    return 0;
}