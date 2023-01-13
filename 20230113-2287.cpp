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
    int rearrangeCharacters(string_view s, string_view target) {
        unordered_map<char, int> t;
        for (char ch : target)
            t[ch]++;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char ch : s)
            cnt[ch - 'a']++;
        int res = INT32_MAX;
        for (auto[k, v] : t)
            res = min(res, cnt[k - 'a'] / v);
        return res;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.rearrangeCharacters("ilovecodingonleetcode", "code") << endl;
    cout << s.rearrangeCharacters("abcba", "abc") << endl;
    cout << s.rearrangeCharacters("abbaccaddaeea", "aaaaa") << endl;
    return 0;
}