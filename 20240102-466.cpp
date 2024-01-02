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
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        vp d;
        for (int i = 0; i < len2; ++i)
        {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < len1; ++k)
                if (s1[k] == s2[j])
                    if (++j == len2)
                    {
                        ++cnt;
                        j = 0;
                    }
            d.emplace_back(cnt, j);
        }
        int ans = 0;
        int id = 0;
        unordered_map<int, pr> ids;
        bool fid = false;
        for (int j = 0; n1; --n1)
        {
            ans += d[j].first;
            j = d[j].second;
            if (fid)
                continue;
            if (ids.count(j))
            {
                auto [rid, rans] = ids[j];
                int cir = n1 / (id - rid) - (n1 % (id - rid) == 0);
                ans += cir * (ans - rans);
                n1 -= cir * (id - rid);
                fid = true;
            }
            ids.emplace(j, pr(id, ans));
            id++;
        }
        return ans / n2;
    }
};

int main()
{
    io;
    return 0;
}
