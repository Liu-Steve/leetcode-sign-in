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
    int maximumScore(int a, int b, int c)
    {
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a + b <= c)
            return a + b;
        return (a + b + c) / 2;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.maximumScore(2, 4, 6) << endl;
    cout << s.maximumScore(4, 4, 6) << endl;
    cout << s.maximumScore(1, 8, 8) << endl;
    return 0;
}