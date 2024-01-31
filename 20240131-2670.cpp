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
    vi distinctDifferenceArray(vi &nums)
    {
        hm s;
        int n = nums.size();
        vi pre(n);
        for (int i = 0; i < n; ++i)
        {
            s.insert(nums[i]);
            pre[i] = s.size();
        }
        s.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            pre[i] -= s.size();
            s.insert(nums[i]);
        }
        return pre;
    }
};

int main()
{
    io;
    return 0;
}
