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
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> cnt(26);
        for (char ch : s)
            cnt[ch - 'a']++;
        string ans;
        int p1;
        int p2;
        for (p1 = 25; p1 >= 0; --p1)
            if (cnt[p1])
                break;
        for (p2 = p1 - 1; p2 >= 0; --p2)
            if (cnt[p2])
                break;
        while (p1 >= 0)
        {
            if (cnt[p1] <= repeatLimit)
            {
                for (int i = 0; i < cnt[p1]; ++i)
                    ans.push_back('a' + p1);
                p1 = p2;
                for (p2 = p1 - 1; p2 >= 0; --p2)
                    if (cnt[p2])
                        break;
                continue;
            }
            for (int i = 0; i < repeatLimit; ++i)
                ans.push_back('a' + p1);
            cnt[p1] -= repeatLimit;
            if (p2 < 0)
                break;
            ans.push_back('a' + p2);
            cnt[p2]--;
            for (; p2 >= 0; --p2)
                if (cnt[p2])
                    break;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
