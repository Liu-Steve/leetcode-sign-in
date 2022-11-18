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

inline bool reput(const vector<int> &v1, const vector<int> &v2) {
    return v1[0] < v2[0];
}

struct cmp {
    bool operator () (const pr &p1, const pr &p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        // buildings from left to right by left point
        sort(buildings.begin(), buildings.end(), reput);
        int b_read = 0;
        int len = buildings.size();
        // bound
        int bound[2 * len];
        for (int i = 0; i < len; ++i) {
            bound[2 * i] = buildings[i][0];
            bound[2 * i + 1] = buildings[i][1];
        }
        sort(bound, bound + 2 * len);
        // priority queue, right, high
        priority_queue<pr, vector<pr>, cmp> q;

        int last_h = 0;
        int this_h;
        for (int b : bound) {
            while(b_read < len && buildings[b_read][0] <= b) {
                q.emplace(buildings[b_read][1], buildings[b_read][2]);
                b_read++;
            }
            while(!q.empty() && q.top().first <= b) {
                q.pop();
            }
            this_h = q.empty() ? 0 : q.top().second;
            if (this_h != last_h) {
                ret.push_back({b, this_h});
                last_h = this_h;
            }
        }
        return ret;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}