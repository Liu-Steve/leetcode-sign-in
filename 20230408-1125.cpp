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
typedef unordered_map<int, ll> memory;

inline int hs(int i, int j)
{
    return (i << 16) | j;
}

class Solution
{
public:
    vi smallestSufficientTeam(vs &req_skills, vector<vs> &people)
    {
        int slen = req_skills.size();
        int plen = people.size();
        unordered_map<string, int> skills_idx;
        for (int i = 0; i < slen; ++i)
            skills_idx[req_skills[i]] = i;
        vi bit_people(plen);
        for (int i = 0; i < plen; ++i)
            for (string sk : people[i])
                bit_people[i] |= 1 << skills_idx[sk];

        memory mem;

        // i: prefix peoples, j: skill mask
        function<ll(int, int)> f = [&](int i, int j) -> ll
        {
            if (j == 0)
                return 0;
            if (i < 0)
                return (1ll << plen) - 1;

            int h = hs(i, j);
            if (mem.count(h))
                return mem[h];

            ll peo_msk_1 = f(i - 1, j);
            ll peo_msk_2 = f(i - 1, j & (~bit_people[i]));
            peo_msk_2 |= (1ll << i);

            if (__builtin_popcountll(peo_msk_1) < __builtin_popcountll(peo_msk_2))
                mem[h] = peo_msk_1;
            else
                mem[h] = peo_msk_2;

            return mem[h];
        };

        ll peo_msk = f(plen - 1, (1 << slen) - 1);
        vi ans;
        for (int i = 0; i < plen; ++i)
            if (peo_msk & (1ll << i))
                ans.emplace_back(i);

        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs s1 = {"java", "nodejs", "reactjs"};
    vector<vs> p1 = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
    vi a1 = s.smallestSufficientTeam(s1, p1);
    for (int i : a1)
        cout << i << ' ';
    cout << endl;

    vs s2 = {"algorithms", "math", "java", "reactjs", "csharp", "aws"};
    vector<vs> p2 = {{"algorithms", "math", "java"}, {"algorithms", "math", "reactjs"}, {"java", "csharp", "aws"}, {"reactjs", "csharp"}, {"csharp", "math"}, {"aws", "java"}};
    vi a2 = s.smallestSufficientTeam(s2, p2);
    for (int i : a2)
        cout << i << ' ';
    cout << endl;

    vs s3 = {"mwobudvo","goczubcwnfze","yspbsez","pf","ey","hkq"};
    vector<vs> p3 = {{},{"mwobudvo"},{"hkq"},{"pf"},{"pf"},{"mwobudvo","pf"},{},{"yspbsez"},{},{"hkq"},{},{},{"goczubcwnfze","pf","hkq"},{"goczubcwnfze"},{"hkq"},{"mwobudvo"},{},{"mwobudvo","pf"},{"pf","ey"},{"mwobudvo"},{"hkq"},{},{"pf"},{"mwobudvo","yspbsez"},{"mwobudvo","goczubcwnfze"},{"goczubcwnfze","pf"},{"goczubcwnfze"},{"goczubcwnfze"},{"mwobudvo"},{"mwobudvo","goczubcwnfze"},{},{"goczubcwnfze"},{},{"goczubcwnfze"},{"mwobudvo"},{},{"hkq"},{"yspbsez"},{"mwobudvo"},{"goczubcwnfze","ey"}};
    vi a3 = s.smallestSufficientTeam(s3, p3);
    for (int i : a3)
        cout << i << ' ';
    cout << endl;

    return 0;
}