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
typedef unordered_map<ll, int> memory;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return heights[a] > heights[b];
        });
        vector<string> ans;
        for (int i = 0; i < n; ++i)
            ans.emplace_back(names[idx[i]]);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
