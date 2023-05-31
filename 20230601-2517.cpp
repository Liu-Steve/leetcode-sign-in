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
private:
    int f(vector<int> &price, int d)
    {
        int last = -d;
        int cnt = 0;
        for (int p : price)
            if (p - last >= d)
            {
                cnt++;
                last = p;
            }
        return cnt;
    }

public:
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        int l = 0;
        int r = (price.back() - price.front()) / (k - 1) + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (f(price, mid) >= k)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
