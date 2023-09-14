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

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        auto sgn = [](int x) -> int{
            return x > 0 ? 1 : (x == 0 ? 0 : -1);
        };

        unordered_map<int, pair<vector<int>, int>> candidates;
        int kx = king[0], ky = king[1];
        for (const auto& queen: queens) {
            int qx = queen[0], qy = queen[1];
            int x = qx - kx, y = qy - ky;
            if (x == 0 || y == 0 || abs(x) == abs(y)) {
                int dx = sgn(x), dy = sgn(y);
                int key = dx * 10 + dy;
                if (!candidates.count(key) || candidates[key].second > abs(x) + abs(y)) {
                    candidates[key] = {queen, abs(x) + abs(y)};
                }
            }
        }

        vector<vector<int>> ans;
        for (const auto& [_, value]: candidates) {
            ans.push_back(value.first);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
