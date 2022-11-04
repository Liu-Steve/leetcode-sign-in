#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int n = sqrt(2 * target);
        int limit = (n + 1)*n / 2;
        while (limit < target || (limit - target) % 2)
        {
            n++;
            limit = (n + 1)*n / 2;
        }
        return n;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.reachNumber(4) << endl;
    return 0;
}