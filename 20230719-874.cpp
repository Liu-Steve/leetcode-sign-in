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
    int robotSim(vi &commands, vv &obstacles)
    {
        const vi bias = {0, 1, 0, -1, 0};
        set<pr> obs;
        for (auto &o : obstacles)
            obs.emplace(o[0], o[1]);
        int dir = 0;
        pr now = {0, 0};
        int ans = 0;
        for (int cmd : commands)
        {
            if (cmd == -2)
            {
                dir = (dir + 3) % 4;
                continue;
            }
            if (cmd == -1)
            {
                dir = (dir + 1) % 4;
                continue;
            }
            while (cmd--)
            {
                pr nxt = {now.first + bias[dir], now.second + bias[dir + 1]};
                if (obs.count(nxt))
                    break;
                now = nxt;
                ans = max(ans, now.first * now.first + now.second * now.second);
            }
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
