#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
private:
    int m;
    int n;
    vvc *pseats;
    memory mem;
    int dfs(int x, int y, int stat)
    {
        int key = (x << 24) | (y << 16) | stat;
        if (mem.count(key))
            return mem[key];
        vvc &seats = *pseats;
        if (x == m)
        {
            mem[key] = 0;
            return 0;
        }
        int dx = x + (y == n - 1);
        int dy = (y + 1) % n;
        int dstat = (stat << 1) & ((1 << (n + 1)) - 1);
        int ans = dfs(dx, dy, dstat);
        if (seats[x][y] == '#' ||
            y != (n - 1) && (stat & (1 << (n - 2))) ||
            y != 0 && ((stat & (1 << n)) || (stat & 1)))
        {
            mem[key] = ans;
            return ans;
        }
        ans = max(ans, dfs(dx, dy, dstat | 1) + 1);
        mem[key] = ans;
        return ans;
    }

public:
    int maxStudents(vvc &seats)
    {
        m = seats.size();
        n = seats[0].size();
        pseats = &seats;
        return dfs(0, 0, 0);
    }
};

int main()
{
    io;
    return 0;
}
