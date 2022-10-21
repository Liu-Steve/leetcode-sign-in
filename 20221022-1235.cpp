#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef struct st
{
    int start;
    int end;
    int profit;
} W;

inline bool cmp(W w1, W w2)
{
    return w1.end < w2.end;
}

class Solution
{
public:
    int find(W *w, int target, int r)
    {
        if (w[r].end <= target)
            return r;
        int l = 0, mid = (l + r) / 2;
        while (r - l > 1)
        {
            if (w[mid].end <= target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
            mid = (l + r) / 2;
        }
        return l;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int len = startTime.size();
        W w[len + 1];
        int p[len + 1];
        w[0].start = 0;
        w[0].end = 0;
        w[0].profit = 0;
        for (int i = 1; i <= len; ++i)
        {
            w[i].start = startTime[i - 1];
            w[i].end = endTime[i - 1];
            w[i].profit = profit[i - 1];
        }
        sort(w + 1, w + len + 1, cmp);
        p[0] = 0;
        for (int i = 1; i <= len; ++i)
        {
            int s = w[i].start;
            int idx = find(w, s, i - 1);
            p[i] = max(p[i - 1], p[idx] + w[i].profit);
        }
        return p[len];
    }
};

int main()
{
    io;
    Solution s;
    vector<int> v1 = {24, 24, 7, 2, 1, 13, 6, 14, 18, 24},
                v2 = {27, 27, 20, 7, 14, 22, 20, 24, 19, 27},
                v3 = {6, 1, 4, 2, 3, 6, 5, 6, 9, 8};
    cout << s.jobScheduling(v1, v2, v3) << endl;
    return 0;
}

/*
[24,24,7,2,1,13,6,14,18,24]
[27,27,20,7,14,22,20,24,19,27]
[6,1,4,2,3,6,5,6,9,8]*/