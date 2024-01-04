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
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> bits(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j])
                    bits[i] |= (1 << j);
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i)
        {
            if (__popcount(i) != numSelect)
                continue;
            int cnt = 0;
            for (int j = 0; j < m; ++j)
                if ((i | bits[j]) == i)
                    cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
