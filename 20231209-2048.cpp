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
    bool valid(int num)
    {
        vector<int> cnt(10, 0);
        while (num != 0)
        {
            int mod = num % 10;
            num /= 10;
            cnt[mod]++;
        }
        if (cnt[0] != 0)
            return false;
        for (int i = 1; i < 10; ++i)
            if (cnt[i] != 0 && cnt[i] != i)
                return false;
        return true;
    }

public:
    int nextBeautifulNumber(int n)
    {
        int ans = n + 1;
        while (!valid(ans))
            ans++;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
