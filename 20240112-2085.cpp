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
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int ans = 0;
        unordered_map<string, int> w1, w2;
        for (string w : words1)
            w1[w]++;
        for (string w : words2)
            w2[w]++;
        for (auto [w, cnt] : w1)
            if (cnt == 1 && w2.count(w) && w2[w] == 1)
                ans++;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
