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
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            int fl = flowerbed[i];
            int left = (i == 0) ? 0 : flowerbed[i - 1];
            int right = (i == len - 1) ? 0 : flowerbed[i + 1];
            if (!left && !right && !fl)
            {
                flowerbed[i] = 1;
                cnt++;
            }
            if (cnt >= n)
                return true;
        }
        return false;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(v1, 1) << endl;
    vi v2 = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(v2, 2) << endl;
    vi v3 = {1, 0, 1, 0, 1, 0};
    cout << s.canPlaceFlowers(v3, 0) << endl;
    vi v4 = {1};
    cout << s.canPlaceFlowers(v4, 0) << endl;
    return 0;
}