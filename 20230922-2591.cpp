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
    int distMoney(int money, int children)
    {
        money -= children;
        if (money < 0)
            return -1;
        int ans = money / 7;
        int r = money % 7;
        if (ans > children)
            return children - 1;
        if (ans == children)
            return children - (r > 0);
        if (ans == 0)
            return 0;
        return ans - (r == 3 && ans == children - 1);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
