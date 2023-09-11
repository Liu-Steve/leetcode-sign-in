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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        priority_queue<int> q;
        sort(courses.begin(), courses.end(), [&](vector<int> &c1, vector<int> &c2)
             { return c1[1] < c2[1]; });
        int cnt = 0;
        int last = 0;
        for (auto &c : courses)
        {
            int dur = c[0];
            int ddl = c[1];
            cnt++;
            last += dur;
            q.emplace(dur);
            if (last > ddl)
            {
                int t = q.top();
                q.pop();
                last -= t;
                cnt--;
            }
        }
        return cnt;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
