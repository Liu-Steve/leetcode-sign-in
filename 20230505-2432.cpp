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
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int lastTime = 0;
        int maxLen = 0;
        int ans = INT32_MAX;
        for (int i = 0; i < logs.size(); ++i)
        {
            int len = logs[i][1] - lastTime;
            lastTime = logs[i][1];
            if (len < maxLen)
                continue;
            if (len > maxLen)
            {
                maxLen = len;
                ans = logs[i][0];
                continue;
            }
            ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
    cout << s.hardestWorker(4, v1) << endl;
    vv v2 = {{1, 1}, {3, 7}, {2, 12}, {7, 17}};
    cout << s.hardestWorker(4, v2) << endl;
    vv v3 = {{0, 10}, {1, 20}};
    cout << s.hardestWorker(2, v3) << endl;
    return 0;
}
