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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        fruits.emplace(fruits.begin(), (vector<int>){-0x3fffffff, 0});
        fruits.emplace_back((vector<int>){0x3fffffff, 0});
        int ans = 0;
        int val = 0;
        int l = 0;
        int r = fruits.size() - 1;
        int sta = 0;
        for (int i = 0; i < fruits.size(); ++i)
        {
            if (sta == 0 && startPos < fruits[i][0])
            {
                l = i;
                r = i;
                break;
            }
            else if (sta == 0 && startPos - fruits[i][0] <= k)
            {
                l = i;
                val += fruits[i][1];
                sta++;
            }
            else if (sta == 1 && startPos < fruits[i][0])
            {
                r = i;
                ans = val;
                break;
            }
            else if (sta == 1)
                val += fruits[i][1];
        }
        int llen = startPos - fruits[l][0];
        int rlen = fruits[r][0] - startPos;
        while (rlen <= k)
        {
            val += fruits[r][1];
            r++;
            while (llen * 2 + rlen > k && llen + rlen * 2 > k)
            {
                val -= fruits[l][1];
                l++;
                llen = startPos - fruits[l][0];
                if (llen < 0)
                    break;
            }
            rlen = fruits[r][0] - startPos;
            if (llen < 0) // make llen == 0
                while (rlen <= k)
                {
                    val += fruits[r][1];
                    r++;
                    rlen = fruits[r][0] - startPos;
                }
            ans = max(ans, val);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{2, 8}, {6, 3}, {8, 6}};
    cout << s.maxTotalFruits(v1, 5, 4) << endl;
    vv v2 = {{0, 3}, {6, 4}, {8, 5}};
    cout << s.maxTotalFruits(v2, 3, 2) << endl;
    return 0;
}
