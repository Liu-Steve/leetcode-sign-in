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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int anscnt = 0;
        int lst = -1;
        int cnt = 0;
        for (int num : nums)
        {
            if (num & 1)
                continue;
            if (num != lst)
                cnt = 1;
            else
                cnt++;
            if (cnt > anscnt)
            {
                ans = num;
                anscnt = cnt;
            }
            lst = num;
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