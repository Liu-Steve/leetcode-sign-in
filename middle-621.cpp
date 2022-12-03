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

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int len1 = tasks.size();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char ch : tasks)
            cnt[ch - 'A']++;
        int mx = -1;
        int mx_cnt = 0;
        for (int i = 0; i < 26; ++i)
        {
            int now_cnt = cnt[i];
            if (now_cnt > mx)
            {
                mx = now_cnt;
                mx_cnt = 1;
            }
            else if (now_cnt == mx)
                mx_cnt++;
        }
        int len2 = mx_cnt + (mx - 1) * (n + 1);
        return max(len1, len2);
    }
};

int main()
{
    io;
    Solution s;
    vector<char> v1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(v1, 2) << endl;
    vector<char> v2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(v2, 0) << endl;
    vector<char> v3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << s.leastInterval(v3, 2) << endl;
    return 0;
}