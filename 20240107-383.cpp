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
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for (char ch : ransomNote)
            cnt1[ch - 'a']++;
        for (char ch : magazine)
            cnt2[ch - 'a']++;
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] > cnt2[i])
                return false;
        return true;
    }
};

int main()
{
    io;
    return 0;
}
