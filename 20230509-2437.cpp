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
typedef unordered_map<ll, int> memory;

class Solution {
public:
    int countTime(string &time) {
        int ans;
        if (time[0] == '?' && time[1] == '?')
            ans = 24;
        else if(time[0] != '?' && time[1] != '?')
            ans = 1;
        else if (time[0] == '?' && time[1] < '4')
            ans = 3;
        else if (time[0] == '?')
            ans = 2;
        else if (time[0] == '2')
            ans = 4;
        else
            ans = 10;
        if (time[3] == '?')
            ans *= 6;
        if (time[4] == '?')
            ans *= 10;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
