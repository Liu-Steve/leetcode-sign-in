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
    int findMaximumXOR(vector<int> &nums)
    {
        int x = 0;
        for (int k = 30; k >= 0; --k)
        {
            unordered_set<int> s;
            for (int num : nums)
                s.insert(num >> k);
            x = x * 2 + 1;
            bool f = false;
            for (int a : nums)
                if (s.count((a >> k) ^ x))
                {
                    f = true;
                    break;
                }
            if (!f)
                x -= 1;
        }
        return x;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
