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

typedef struct st1
{
    vector<int> nxt;
    bool vis = false;
} Node;

class Solution
{
private:
    double dfs(vector<Node> &nds, int now, int t, int target)
    {
        nds[now].vis = true;
        if (now == target)
            return t == 0 || nds[now].nxt.size() <= 1 - (now == 1);
        else if (t <= 0)
            return 0;
        double ans = 0;
        int choice = 0;
        for (int nxt : nds[now].nxt)
            if (nds[nxt].vis == false)
            {
                ans += dfs(nds, nxt, t - 1, target);
                choice++;
            }
        if (choice == 0)
            return 0;
        ans /= choice;
        return ans;
    }

public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        vector<Node> nds(n + 1);
        for (auto e : edges)
        {
            nds[e[0]].nxt.emplace_back(e[1]);
            nds[e[1]].nxt.emplace_back(e[0]);
        }
        return dfs(nds, 1, t, target);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
