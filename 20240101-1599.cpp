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
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        int ans = -1;   // answer
        int mx = 0;     // max profit
        int pro = 0;    // now profit
        int remain = 0; // remain people not take
        int len = customers.size();
        for (int i = 0; i < len || remain; ++i)
        {
            if (i < len)
                remain += customers[i];
            pro -= runningCost;
            int up = min(4, remain);
            remain -= up;
            pro += up * boardingCost;
            if (pro > mx)
            {
                mx = pro;
                ans = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {8, 3};
    cout << s.minOperationsMaxProfit(v1, 5, 6) << endl;
    vi v2 = {10, 9, 6};
    cout << s.minOperationsMaxProfit(v2, 6, 4) << endl;
    vi v3 = {3, 4, 0, 5, 1};
    cout << s.minOperationsMaxProfit(v3, 1, 92) << endl;
    return 0;
}