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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
private:
    int cnt(string_view s1, string_view s2)
    {
        int ans = 0;
        int len = min(s1.size(), s2.size());
        int dif = 0;
        for (int i = 0; i < len; ++i)
        {
            dif += s1[i] != s2[i];
            if (dif == 1)
                ans++;
            else if (dif > 1)
                break;
        }
        return ans;
    }

public:
    int countSubstrings(string_view s, string_view t)
    {
        if (s.size() > t.size())
            swap(s, t);
        int len1 = s.size();
        int len2 = t.size();
        int ans = 0;
        for (int i = 0; i < len1; ++i)
            for (int j = 0; j < len2; ++j)
                ans += cnt(s.substr(i), t.substr(j));
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}