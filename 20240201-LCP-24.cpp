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
    vi numsGame(vi &nums)
    {
        int n = nums.size();
        vi res(n);
        priority_queue<int> lower;
        priority_queue<int, vi, greater<int>> upper;
        ll lowerSum = 0, upperSum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i] - i;
            if (lower.empty() || lower.top() >= x)
            {
                lowerSum += x;
                lower.push(x);
                if (lower.size() > upper.size() + 1)
                {
                    upperSum += lower.top();
                    upper.push(lower.top());
                    lowerSum -= lower.top();
                    lower.pop();
                }
            }
            else
            {
                upperSum += x;
                upper.push(x);
                if (lower.size() < upper.size())
                {
                    lowerSum += upper.top();
                    lower.push(upper.top());
                    upperSum -= upper.top();
                    upper.pop();
                }
            }
            if ((i + 1) % 2 == 0)
                res[i] = (upperSum - lowerSum) % MOD;
            else
                res[i] = (upperSum - lowerSum + lower.top()) % MOD;
        }
        return res;
    }
};

int main()
{
    io;
    return 0;
}
