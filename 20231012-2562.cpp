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
private:
    int ser(int a, int b)
    {
        if (b < 10)
            return a * 10 + b;
        if (b < 100)
            return a * 100 + b;
        if (b < 1000)
            return a * 1000 + b;
        if (b < 10000)
            return a * 10000 + b;
        return a * 100000 + b;
    }

public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1 - i; ++i)
            ans += ser(nums[i], nums[n - 1 - i]);
        if (n % 2)
            ans += nums[n / 2];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
