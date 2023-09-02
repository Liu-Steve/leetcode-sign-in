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
    int captureForts(vector<int> &forts)
    {
        int last = -2;
        int cnt = 0;
        int mx = 0;
        for (int num : forts)
        {
            if (num)
            {
                if (num + last == 0)
                    mx = max(mx, cnt);
                last = num;
                cnt = 0;
            }
            else
                cnt++;
        }
        return mx;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
