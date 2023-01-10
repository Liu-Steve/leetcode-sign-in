#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;

class Solution {
public:
    bool digitCount(string_view num) {
        int cnt[10];
        int n = num.size();
        memset(cnt, 0, sizeof(cnt));
        for (char ch : num)
            cnt[ch - '0']++;
        for (int i = 0; i < n; ++i)
            if (cnt[i] + '0' != num[i])
                return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.digitCount("1210") << endl;
    cout << s.digitCount("030") << endl;
    return 0;
}