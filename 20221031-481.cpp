#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int magicalString(int n)
    {
        queue<int> q;
        int ret = 0;
        int st = 2;
        while (n--) {
            st = (st == 1) ? 2 : 1;
            q.emplace(st);
            int th = q.front();
            ret += (th == 1);
            q.pop();
            if (th == 2)
                q.emplace(st);
        }
        return ret;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.magicalString(1) << endl;
    return 0;
}