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

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0;
        int r = arr.size();
        for (int i = 1; i < r; ++i)
            if (arr[i] >= arr[i - 1])
                l = i;
            else
                break;
        int ans = r - l - 1;
        if (ans == 0)
            return 0;
        int lst = INT32_MAX;
        for (r = r - 1; r >= 0; r--)
        {
            if (arr[r] > lst)
                break;
            lst = arr[r];
            while(l >= 0 && arr[l] > arr[r])
                l--;
            ans = min(ans, r - l - 1);
            if (ans == 0)
                break;
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