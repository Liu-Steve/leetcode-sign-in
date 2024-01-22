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

class Solution {
public:
    int maximumSwap(int num) {
        ostringstream ss;
        ss << num;
        string sn = ss.str();
        set<pair<char, int>> mp;
        for (int i = 0; i < sn.size(); ++i)
            mp.emplace(sn[i], i);
        for (int i = 0; i < sn.size() - 1; ++i)
        {
            auto [ch, p] = *mp.rbegin();
            if (ch <= sn[i])
            {
                mp.erase(pair{sn[i], i});
                continue;
            }
            swap(sn[i], sn[p]);
            break;
        }
        stringstream sss;
        sss << sn;
        int ans;
        sss >> ans;
        return ans;
    }
};

int main()
{
    io;

    Solution s;
    s.maximumSwap(98863);

    return 0;
}
