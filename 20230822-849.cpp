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

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lst = -1;
        int ans = 0;
        int n = seats.size();
        for (int i = 0; i < n; ++i)
            if (seats[i] == 1)
            {
                ans = max(ans, (lst == -1 ? i : (i - lst) / 2));
                lst = i;
            }
        ans = max(ans, n - 1 - lst);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
