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
typedef pair<int, int> pr;
typedef vector<pair<int, int>> vp;

const ll MOD = 1000000007;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        sort(points.begin(), points.end());
        int plen = points.size();
        int qlen = queries.size();
        vector<int> res(qlen);
        int cnt = 0;
        for (vector<int> &q : queries)
        {
            int x = q[0];
            int y = q[1];
            int rid = q[2];
            int lidx, ridx;
            vector<int> llim = {x - rid, y};
            vector<int> rlim = {x + rid, y};
            int l = 0;
            int r = plen;
            int mid;
            while (l + 1 < r)
            {
                mid = (l + r) / 2;
                if (points[mid] < llim)
                    l = mid;
                else
                    r = mid;
            }
            lidx = l;
            l = 0;
            r = plen - 1;
            while (l + 1 < r)
            {
                mid = (l + r) / 2;
                if (points[mid] > rlim)
                    r = mid;
                else
                    l = mid;
            }
            ridx = r;
            for (int i = lidx; i <= ridx; ++i)
            {
                int px = points[i][0];
                int py = points[i][1];
                res[cnt] +=
                    ((px - x) * (px - x) + (py - y) * (py - y) <= rid * rid);
            }
            cnt++;
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vv p1 = {{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    vv q1 = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    vi r1 = s.countPoints(p1, q1);
    for (int i : r1)
        cout << i << ' ';
    cout << endl;
    vv p2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    vv q2 = {{1, 2, 2}, {2, 2, 2}, {4, 3, 2}, {4, 3, 3}};
    vi r2 = s.countPoints(p2, q2);
    for (int i : r2)
        cout << i << ' ';
    cout << endl;
    return 0;
}