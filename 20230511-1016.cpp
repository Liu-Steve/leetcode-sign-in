#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

class Solution {
public:
    bool queryString(string_view s, int n) {
        if (n == 1)
            return s.find('1') != s.npos;

        int a = n;
        int k = -1;
        while (a)
        {
            a >>= 1;
            k++;
        }
        int m = s.size();
        if (m < (1 << (k - 1)) + k - 1 ||
            m < (n - (1 << k)) + k + 1)
            return false;
        
        unordered_set<int> h;
        int now = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            now <<= 1;
            now += (s[i] != '0');
            h.insert(now);
            if (i < k)
                continue;
            now &= (1 << k) - 1;
            h.insert(now);
        }
        for (int i = 1 << (k - 1); i <= n; ++i)
            if (!h.count(i))
                return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    cout << s.queryString("1", 1) << endl;
    cout << s.queryString("0", 1) << endl;
    cout << s.queryString("0110", 3) << endl;
    cout << s.queryString("0110", 4) << endl;
    return 0;
}
