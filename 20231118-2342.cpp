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
    int maximumSum(vector<int> &nums)
    {
        int ans = -1;

        auto sum = [](int num)
        {
            int s = 0;
            while (num)
            {
                s += num % 10;
                num /= 10;
            }
            return s;
        };

        map<int, vector<int>> eq;
        for (int num : nums)
        {
            int k = sum(num);
            if (!eq.count(k))
                eq[k] = vector<int>();
            eq[k].emplace_back(num);
        }

        for (auto &[k, v] : eq)
        {
            if (v.size() < 2)
                continue;
            sort(v.begin(), v.end(), greater<int>());
            ans = max(ans, v[0] + v[1]);
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
