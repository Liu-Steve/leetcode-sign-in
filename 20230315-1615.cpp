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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int maximalNetworkRank(int n, vv& roads) {

        auto hash = [&](int city1, int city2){
            return city1 * n + city2;
        };

        vp rank(n);
        hm rset;
        for (int i = 0; i < n; ++i)
            rank[i] = {i, 0};
        for (auto &r: roads)
        {
            rank[r[0]].second++;
            rank[r[1]].second++;
            rset.insert(hash(r[0], r[1]));
            rset.insert(hash(r[1], r[0]));
        }
        sort(rank.begin(), rank.end(), [](const pr &p1, const pr &p2){
            return p1.second > p2.second;
        });
        int ans = rank[0].second + rank[1].second;
        if (!rset.count(hash(rank[0].first, rank[1].first)))
            return ans;
        bool eq = rank[0].second == rank[1].second;
        for (int i = 2; i < n; ++i)
        {
            if (rank[i].second < rank[1].second)
                break;
            if (!rset.count(hash(rank[0].first, rank[i].first)))
                return ans;
            if (eq && !rset.count(hash(rank[1].first, rank[i].first)))
                return ans;
        }
        return ans - 1;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{2, 4}};
    cout << s.maximalNetworkRank(6, v1) << endl;
    return 0;
}