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
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for (char c : word1)
            cnt1[c - 'a']++;
        for (char c : word2)
            cnt2[c - 'a']++;
        for (int i = 0; i < 26; ++i)
            if (!cnt1[i] && cnt2[i] || cnt1[i] && !cnt2[i])
                return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] != cnt2[i])
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
