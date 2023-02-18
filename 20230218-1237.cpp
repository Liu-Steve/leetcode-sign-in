#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class CustomFunction
{
public:
    int f(int x, int y)
    {
        return x * y;
    }
};

// 二分 复杂度 O(mlogn)

// class Solution
// {
// public:
//     vector<vector<int>> findSolution(CustomFunction &c, int z)
//     {
//         vector<vector<int>> ans;
//         for (int x = 1; x <= 1000; ++x)
//         {
//             int l = 1;
//             int r = 1000;
//             int lv = c.f(x, l);
//             int rv = c.f(x, r);
//             if (lv == z)
//                 ans.emplace_back(vector<int>({x, l}));
//             if (rv == z)
//                 ans.emplace_back(vector<int>({x, r}));
//             if (lv >= z)
//                 break;
//             else if (rv <= z)
//                 continue;
//             while (r - l > 1)
//             {
//                 int m = (l + r) / 2;
//                 int mv = c.f(x, m);
//                 if (mv == z)
//                 {
//                     ans.emplace_back(vector<int>({x, m}));
//                     break;
//                 }
//                 else if (mv > z)
//                 {
//                     r = m;
//                     rv = mv;
//                 }
//                 else
//                 {
//                     l = m;
//                     lv = mv;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 双指针 复杂度 O(m + n)

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& c, int z) {
        vector<vector<int>> ans;
        int y = 1000;
        for (int x = 1; x <= 1000; ++x)
        {
            int f = c.f(x, y);
            while (f > z)
            {
                if (!(--y))
                    return ans;
                f = c.f(x, y);
            }
            if (f == z)
                ans.emplace_back(vector<int>({x, y}));
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    CustomFunction c;
    for (auto v : s.findSolution(c, 50))
        cout << v[0] << ' ' << v[1] << endl;
    return 0;
}