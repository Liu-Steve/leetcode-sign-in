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

class Solution
{
private:
    inline string num2str(int num)
    {
        string str = "";
        str += num / 2500 + ' ';
        str += (num / 50) % 50 + ' ';
        str += num % 50 + ' ';
        return str;
    }

public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        unordered_map<string, int> cnt;
        for (auto v : grid)
        {
            string str = "";
            for (int num : v)
                str += num2str(num);
            cnt[str]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            string str = "";
            for (int j = 0; j < n; ++j)
                str += num2str(grid[j][i]);
            if (cnt.count(str))
                ans += cnt[str];
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    cout << s.equalPairs(v1) << endl;
    return 0;
}
