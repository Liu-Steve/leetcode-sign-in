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

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res[46];
        memset(res, 0, sizeof(res));
        int n = lowLimit;
        int idx = 0;
        while (n)
        {
            idx += n % 10;
            n /= 10;
        }
        for (int i = lowLimit; i <= highLimit; ++i)
        {
            res[idx]++;
            n = i;
            while (n % 10 == 9)
            {
                n /= 10;
                idx -= 9;
            }
            ++idx;
        }
        int max_res = 0;
        for (int i = 0; i < 46; ++i)
            max_res = max(max_res, res[i]);
        return max_res;
    }
};

int main() {
    io;
    Solution s;
    cout << s.countBalls(1, 10) << endl;
    cout << s.countBalls(5, 15) << endl;
    cout << s.countBalls(19, 28) << endl;
    return 0;
}