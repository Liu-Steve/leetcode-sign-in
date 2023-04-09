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
typedef unordered_map<int, int> memory;

class Solution {
public:
    bool checkDistances(string_view s, vector<int>& distance) {
        vector<int> reald(26, -1);
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            char ch = s[i];
            if (reald[ch - 'a'] == -1)
                reald[ch - 'a'] = i;
            else
                reald[ch - 'a'] = i - 1 - reald[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if (reald[i] != -1 && reald[i] != distance[i])
                return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}