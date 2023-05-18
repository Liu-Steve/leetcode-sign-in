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
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        int len1 = arr1.size();
        int len2 = arr2.size();
        int add = 0;
        int i = 1;
        while (i <= max(len1, len2) || add)
        {
            int num1 = (i <= len1 ? arr1[len1 - i] : 0);
            int num2 = (i <= len2 ? arr2[len2 - i] : 0);
            int num = num1 + num2 + add;
            if (num == 0 || num == 1)
            {
                ans.emplace_back(num);
                add = 0;
            }
            else if (num == -1)
            {
                ans.emplace_back(1);
                add = 1;
            }
            else if (num == 2 || num == 3)
            {
                ans.emplace_back(num - 2);
                add = -1;
            }
            i++;
        }
        while (ans.size() > 1 && ans[ans.size() - 1] == 0)
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 1, 1, 1, 1};
    vi v2 = {1, 0, 1};
    vi ans = s.addNegabinary(v1, v2);
    return 0;
}
