#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius)
    {
        int xmin = towers[0][0];
        int ymin = towers[0][1];
        int xmax = xmin;
        int ymax = ymin;
        int len = towers.size();
        for (int i = 1; i < len; ++i) {
            int x = towers[i][0];
            int y = towers[i][1];
            xmin = min(xmin, x);
            ymin = min(ymin, y);
            xmax = max(xmax, x);
            ymax = max(ymax, y);
        }
        vector<int> res(2);
        int sig = 0;
        for (int i = xmin; i <= xmax; ++i)
        {
            for (int j = ymin; j <= ymax; ++j)
            {
                int score = 0;
                for (int k = 0; k < len; ++k)
                {
                    double d2 = (i - towers[k][0]) * (i - towers[k][0]) + 
                        (j - towers[k][1]) * (j - towers[k][1]);
                    if (d2 > radius * radius)
                        continue;
                    score += towers[k][2] / (1 + sqrt(d2));
                }
                if (score > sig)
                {
                    res[0] = i;
                    res[1] = j;
                    sig = score;
                }
            }
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vector<vector<int>> v = {{1,2,5},{2,1,7},{3,1,9}};
    vector<int> res = s.bestCoordinate(v, 2);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}