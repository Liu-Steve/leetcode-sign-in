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
public:
    string findReplaceString(const string &s, vi &indices, vs &sources, vs &targets)
    {
        int k = indices.size();
        unordered_map<int, pr> rep;
        for (int i = 0; i < k; ++i)
        {
            int idx = indices[i];
            const string &so = sources[i];
            if (idx + so.size() > s.size())
                continue;
            bool v = true;
            for (int j = 0; j < so.size(); ++j)
                if (s[idx + j] != so[j])
                {
                    v = false;
                    break;
                }
            if (!v)
                continue;
            rep.emplace(idx, pr{i, so.size()});
        }
        stringstream ss;
        for (int i = 0; i < s.size(); ++i)
        {
            if (rep.count(i) == 0)
            {
                ss << s[i];
                continue;
            }
            ss << targets[rep[i].first];
            i += rep[i].second - 1;
        }
        return ss.str();
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
