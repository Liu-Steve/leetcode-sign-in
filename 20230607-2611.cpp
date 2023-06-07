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
typedef unordered_map<int, int> memory;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        auto cmp = [&](int n1, int n2){
            int d1 = reward1[n1] - reward2[n1];
            int d2 = reward1[n2] - reward2[n2];
            return d1 > d2;
        };
        sort(idx.begin(), idx.end(), cmp);

        int ans = 0;
        for (int i = 0; i < k; ++i)
            ans += reward1[idx[i]];
        for (int i = k; i < n; ++i)
            ans += reward2[idx[i]];
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
