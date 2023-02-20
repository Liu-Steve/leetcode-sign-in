#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        bool flush = true;
        for (int i = 1; i < 5; ++i)
            if (suits[0] != suits[i])
                flush = false;
        if (flush)
            return "Flush";
        sort(ranks.begin(), ranks.end());
        int cnt = 0;
        int mx = 0;
        for (int i = 1; i < 5; ++i)
        {
            cnt = (ranks[i] == ranks[i - 1]) ? cnt + 1 : 0;
            mx = max(mx, cnt);
        }
        if (mx >= 2)
            return "Three of a Kind";
        else if (mx)
            return "Pair";
        else
            return "High Card";
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}