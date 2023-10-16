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

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        ll sum = 0;
        for (int num : nums)
            sum ^= num;
        ll p = sum & -sum;
        int x1 = 0;
        int x2 = 0;
        for (int num : nums)
        {
            if (num & p)
                x1 ^= num;
            else
                x2 ^= num;
        }
        return vector<int>{x1, x2};
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
