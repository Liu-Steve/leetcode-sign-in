#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for (int num : coins)
        {
            if (num > sum + 1)
                break;
            sum += num;
        }
        return sum + 1;
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 3};
    cout << s.getMaximumConsecutive(v1) << endl;
    vi v2 = {1, 1, 1, 4};
    cout << s.getMaximumConsecutive(v2) << endl;
    vi v3 = {1, 4, 10, 3, 1};
    cout << s.getMaximumConsecutive(v3) << endl;
    return 0;
}