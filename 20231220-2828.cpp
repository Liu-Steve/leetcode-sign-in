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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        if (n != s.size())
            return false;
        for (int i = 0; i < n; ++i)
            if (words[i][0] != s[i])
                return false;
        return true;
    }
};

int main()
{
    io;
    return 0;
}
