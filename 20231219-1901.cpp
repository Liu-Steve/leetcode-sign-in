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

class Solution
{
private:
    int imax(vi &a)
    {
        return max_element(a.begin(), a.end()) - a.begin();
    }

public:
    vi findPeakGrid(vv &mat)
    {
        int l = 0;
        int r = mat.size() - 1;
        while (l < r)
        {
            int i = (l + r) / 2;
            int j = imax(mat[i]);
            if (i == mat.size() - 1 || mat[i][j] > mat[i + 1][j])
                r = i;
            else
                l = i + 1;
        }
        return {l, imax(mat[l])};
    }
};

int main()
{
    io;
    return 0;
}
