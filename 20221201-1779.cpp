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
    int nearestValidPoint(int x, int y, const vector<vector<int>> &points)
    {
        int res = -1;
        int dis = INT32_MAX;
        int len = points.size();
        for (int i = 0; i < len; ++i)
        {
            int px = points[i][0];
            int py = points[i][1];
            if (x != px && y != py)
                continue;
            int pdis = abs(px - x + py - y);
            if (!pdis)
                return i;
            if (pdis < dis)
            {
                res = i;
                dis = pdis;
            }
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
    cout << s.nearestValidPoint(3, 4, v1) << endl;
    return 0;
}