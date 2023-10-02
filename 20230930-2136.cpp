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
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int n1, int n2) {
            return growTime[n1] > growTime[n2];
        });
        int ans = 0;
        int sum = 0;
        for (int i : idx)
        {
            sum += plantTime[i];
            ans = max(ans, sum + growTime[i]);
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
