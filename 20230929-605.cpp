#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

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
    return 0;
}
