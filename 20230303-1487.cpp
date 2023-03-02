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
    vector<string> getFolderNames(vector<string> &names)
    {
        vector<string> ans;
        unordered_map<string, int> hash;
        for (string &name : names)
        {
            if (hash.count(name) == 0)
            {
                ans.emplace_back(name);
                hash.insert({name, 1});
                continue;
            }
            int cnt = hash[name];
            string newname = name + '(' + to_string(cnt) + ')';
            while (hash.count(newname) > 0)
            {
                newname = name + '(' + to_string(cnt) + ')';
                cnt++;
            }
            ans.emplace_back(newname);
            hash[name] = cnt;
            hash.insert({newname, 1});
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}