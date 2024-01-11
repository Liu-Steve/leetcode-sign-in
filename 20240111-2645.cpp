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
public:
    int addMinimum(string word)
    {
        int cnt = 0;
        char p = 'a';
        for (char w : word)
        {
            while (w != p)
            {
                p++;
                if (p > 'c')
                {
                    p = 'a';
                    cnt++;
                }
            }
            p++;
            if (p > 'c')
            {
                p = 'a';
                cnt++;
            }
        }
        if (p != 'a')
            cnt++;
        return cnt * 3 - word.size();
    }
};

int main()
{
    io;
    return 0;
}
