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

// O(nlogn)
// class Solution
// {
// public:
//     vb checkArithmeticSubarrays(vi &nums, vi &l, vi &r)
//     {
//         int m = l.size();
//         vb ans(m);
//         for (int i = 0; i < m; ++i)
//         {
//             vi sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
//             sort(sub.begin(), sub.end());
//             int len = sub.size();
//             int isari = true;
//             for (int i = 1; i < len; ++i)
//                 if (sub[i] - sub[i - 1] != sub[1] - sub[0])
//                 {
//                     isari = false;
//                     break;
//                 }
//             if (len == 1)
//                 isari = false;
//             ans[i] = isari;
//         }
//         return ans;
//     }
// };

// O(n)
class Solution
{
public:
    vb checkArithmeticSubarrays(vi &nums, vi &l, vi &r)
    {
        int m = l.size();
        vb ans(m);
        for (int i = 0; i < m; ++i)
        {
            vi sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int l = sub.size();
            int le = sub[0];
            int gr = sub[0];
            for (int num : sub)
            {
                if (num < le)
                    le = num;
                else if (num > gr)
                    gr = num;
            }
            if (gr == le)
            {
                ans[i] = true;
                continue;
            }
            if ((gr - le) % (l - 1))
            {
                ans[i] = false;
                continue;
            }
            int d = (gr - le) / (l - 1);
            vb k(l, false);
            int isari = true;
            for (int num : sub)
            {
                if ((num - le) % d)
                {
                    isari = false;
                    break;
                }
                int idx = (num - le) / d;
                if (k[idx])
                {
                    isari = false;
                    break;
                }
                k[idx] = true;
            }
            ans[i] = isari;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}