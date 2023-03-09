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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int minimumRecolors(string &blocks, int k)
    {
        queue<char> q;
        int mx = 0;
        int now = 0;
        for (char ch : blocks)
        {
            q.push(ch);
            if (ch == 'B')
                now++;
            if (q.size() > k)
            {
                if(q.front() == 'B')
                    now--;
                q.pop();
            }
            mx = max(mx, now);
        }
        return k - mx;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}