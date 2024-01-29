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
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; ++i)
            pos[ring[i] - 'a'].push_back(i);
        vector<int> sum1(n, 0), sum2(n, INT32_MAX);
        vector<int> &lst = *(new vector<int>(1, 0));
        for (char k : key)
        {
            vector<int> &now = pos[k - 'a'];
            sum2 = vector<int>(n, INT32_MAX);
            for (int p2 : now)
                for (int p1 : lst)
                    sum2[p2] = min(sum2[p2], sum1[p1] + min(abs(p1 - p2), n - abs(p1 - p2)));
            swap(sum1, sum2);
            lst = pos[k - 'a'];
        }
        int ans = INT32_MAX;
        for (int p : lst)
            ans = min(ans, sum1[p]);
        return ans + key.size();
    }
};

int main()
{
    io;
    return 0;
}
