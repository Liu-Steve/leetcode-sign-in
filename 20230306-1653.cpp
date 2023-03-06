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
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int minimumDeletions(string &s)
    {
        int len = s.size();
        int cnt = 0;
        int minn = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'a')
                minn = min(minn + 1, cnt);
            else
                cnt++;
        }
        return minn;
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "aababbab";
    cout << s.minimumDeletions(s1) << endl;
    string s2 = "bbaaaaabb";
    cout << s.minimumDeletions(s2) << endl;
    return 0;
}