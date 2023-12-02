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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size() / 2;
        vector<int> cnt(10);
        for (int i = 0; i < n; i++)
        {
            int color = 0;
            if (rings[2 * i] == 'R')
                color = 1;
            if (rings[2 * i] == 'G')
                color = 2;
            if (rings[2 * i] == 'B')
                color = 4;
            int num = rings[2 * i + 1] - '0';
            cnt[num] |= color;
        }
        int ans = 0;
        for (int c : cnt)
            ans += (c == 7);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
