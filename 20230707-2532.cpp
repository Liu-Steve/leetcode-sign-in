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
    int findCrossingTime(int n, int k, vv &time)
    {
        auto cmp = [&](int idx1, int idx2)
        {
            int t1 = time[idx1][0] + time[idx1][2];
            int t2 = time[idx2][0] + time[idx2][2];
            return t1 != t2 ? t1 < t2 : idx1 < idx2;
        };

        priority_queue<int, vi, decltype(cmp)> wait_l(cmp), wait_r(cmp);
        priority_queue<pr, vp, greater<pr>> work_l, work_r;

        for (int i = 0; i < k; ++i)
            wait_l.emplace(i);
        
        int remain = n;
        int now = 0;
        while (remain > 0 || !wait_r.empty() || !work_r.empty())
        {
            while(!work_l.empty() && work_l.top().first <= now)
            {
                wait_l.emplace(work_l.top().second);
                work_l.pop();
            }
            while(!work_r.empty() && work_r.top().first <= now)
            {
                wait_r.emplace(work_r.top().second);
                work_r.pop();
            }

            if (!wait_r.empty())
            {
                int who = wait_r.top();
                wait_r.pop();
                now += time[who][2];
                work_l.emplace(now + time[who][3], who);
            }
            else if (!wait_l.empty() && remain > 0)
            {
                int who = wait_l.top();
                wait_l.pop();
                now += time[who][0];
                work_r.emplace(now + time[who][1], who);
                remain--;
            }
            else
            {
                int newTime = INT32_MAX;
                if (!work_l.empty())
                    newTime = min(newTime, work_l.top().first);
                if (!work_r.empty())
                    newTime = min(newTime, work_r.top().first);
                if (newTime != INT32_MAX)
                    now = newTime;
            }
        }

        return now;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
