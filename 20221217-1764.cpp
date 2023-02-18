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

class Solution {
private:
    vi getNxt(vi &pat)
    {
        int len = pat.size();
        vi nxt(len + 1);
        nxt[0] = -1;
        int i = 0;
        int j = -1;
        while (i < len)
        {
            if (j == -1 || pat[i] == pat[j])
            {
                ++i;
                ++j;
                nxt[i] = j;
            }
            else
                j = nxt[j];
        }
        return nxt;
    }
public:
    bool canChoose(vv& groups, vi& nums) {
        int i1 = 0;
        int i2;
        int ig = 0;
        int len1 = nums.size();
        int len2;
        int leng = groups.size();
        while (ig < leng)
        {
            i2 = 0;
            len2 = groups[ig].size();
            vi &pat = groups[ig];
            vi nxt = getNxt(pat);
            while (i1 < len1 && i2 < len2)
            {
                if (i2 == -1 || nums[i1] == pat[i2])
                {
                    i1++;
                    i2++; 
                }
                else
                    i2 = nxt[i2];
            }
            if (i2 != len2)
                return false;
            ig++;
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}