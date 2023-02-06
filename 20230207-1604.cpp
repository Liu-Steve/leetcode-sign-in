#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
private:
    int s2t(string &timeStr)
    {
        return (timeStr[0] - '0') * 600 +
               (timeStr[1] - '0') * 60 +
               (timeStr[3] - '0') * 10 +
               (timeStr[4] - '0');
    }

public:
    vs alertNames(vs &keyName, vs &keyTime)
    {
        vs ans;
        int n = keyName.size();
        ans.reserve(n / 3);
        unordered_map<string, set<int>> rec;
        for (int i = 0; i < n; ++i)
        {
            const auto &it = rec.find(keyName[i]);
            if (it == rec.end())
                rec.insert({keyName[i], {s2t(keyTime[i])}});
            else
                (*it).second.insert(s2t(keyTime[i]));
        }
        for (auto &[name, ts] : rec)
        {
            int t1 = -100, t2 = -100;
            for (int t : ts)
            {
                if (t - t1 <= 60)
                {
                    ans.emplace_back(name);
                    break;
                }
                t1 = t2;
                t2 = t;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    vs v2 = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    vs v3 = s.alertNames(v1, v2);
    for (auto &s : v3)
        cout << s << ' ';
    cout << endl;
    return 0;
}