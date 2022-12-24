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
    int captureForts(vector<int> &forts)
    {
        int last = -2;
        int cnt = 0;
        int mx = 0;
        for (int num : forts)
        {
            if (num)
            {
                if (num + last == 0)
                    mx = max(mx, cnt);
                last = num;
                cnt = 0;
            }
            else
                cnt++;
        }
        return mx;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 0, 0, -1, 0, 0, 0, 0, 1};
    cout << s.captureForts(v1) << endl;
    vi v2 = {0, 0, 1, -1};
    cout << s.captureForts(v2) << endl;
    return 0;
}