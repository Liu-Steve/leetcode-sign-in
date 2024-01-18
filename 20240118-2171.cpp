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
    long long minimumRemoval(vector<int> &beans)
    {
        sort(beans.begin(), beans.end());
        long long sum = 0;
        long long n = beans.size();
        for (int i = 0; i < n; ++i)
            sum += beans[i] - beans[0];
        long long ans = sum;
        for (int i = 0; i < n - 1; ++i)
        {
            sum -= (n - i - 1) * (beans[i + 1] - beans[i]);
            sum += beans[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
