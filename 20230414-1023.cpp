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
typedef unordered_map<int, int> memory;

class Solution
{
private:
    bool match(string_view q, string_view pat)
    {
        int p1 = 0;
        int len1 = q.size();
        int p2 = 0;
        int len2 = pat.size();
        while (p2 < len2)
        {
            if (p1 >= len1)
                return false;
            if (q[p1] == pat[p2])
            {
                p1++;
                p2++;
                continue;
            }
            else if (q[p1] >= 'a')
            {
                p1++;
                continue;
            }
            else
                return false;
        }
        while (p1 < len1)
        {
            if (q[p1] <= 'Z')
                return false;
            p1++;
        }
        return true;
    }

public:
    vector<bool> camelMatch(vector<string> &queries, string_view pattern)
    {
        vector<bool> ans;
        for (string &q : queries)
            ans.emplace_back(match(q, pattern));
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs s1 = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    vb a1 = s.camelMatch(s1, "FB");
    for (bool i : a1)
        cout << i << ' ';
    cout << endl;
    return 0;
}