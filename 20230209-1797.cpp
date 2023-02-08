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

class AuthenticationManager
{
private:
    int len;
    unordered_map<string, int> exp;

public:
    AuthenticationManager(int timeToLive)
    {
        len = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        exp.insert({tokenId, currentTime + len});
    }

    void renew(string tokenId, int currentTime)
    {
        const auto &it = exp.find(tokenId);
        if (it == exp.end())
            return;
        if ((*it).second <= currentTime)
        {
            exp.erase(it);
            return;
        }
        (*it).second = currentTime + len;
    }

    int countUnexpiredTokens(int currentTime)
    {
        int ans = 0;
        vector<string> rm;
        for (auto &it : exp)
            if (it.second > currentTime)
                ans++;
            else
                rm.emplace_back(it.first);
        for (auto it : rm)
            exp.erase(it);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}