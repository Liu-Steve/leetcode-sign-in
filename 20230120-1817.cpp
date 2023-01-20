#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution
{
public:
    vi findingUsersActiveMinutes(vv &logs, int k)
    {
        vi res(k);
        sort(logs.begin(), logs.end());
        int len = logs.size();
        int t = 1;
        for (int i = 1; i < len; ++i)
        {
            if (logs[i][0] != logs[i - 1][0])
            {
                res[t - 1]++;
                t = 1;
            }
            else if (logs[i][1] != logs[i - 1][1])
                t++;
        }
        res[t - 1]++;
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    vi r1 = s.findingUsersActiveMinutes(v1, 5);
    for (int i : r1)
        cout << i << ' ';
    cout << endl;
    vv v2 = {{1, 1}, {2, 2}, {2, 3}};
    vi r2 = s.findingUsersActiveMinutes(v2, 4);
    for (int i : r2)
        cout << i << ' ';
    cout << endl;
    return 0;
}