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
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2)
    {
        if (x <= x1 && y <= y1)
            return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r;
        else if (x <= x1 && y >= y2)
            return (x1 - x) * (x1 - x) + (y - y2) * (y - y2) <= r * r;
        else if (x >= x2 && y <= y1)
            return (x - x2) * (x - x2) + (y1 - y) * (y1 - y) <= r * r;
        else if (x >= x2 && y >= y2)
            return (x - x2) * (x - x2) + (y - y2) * (y - y2) <= r * r;
        else if (x <= x1)
            return x1 - x <= r;
        else if (x >= x2)
            return x - x2 <= r;
        else if (y <= y1)
            return y1 - y <= r;
        else if (y >= y2)
            return y - y2 <= r;
        return true;
    }
};

int main()
{
    io;
    return 0;
}
