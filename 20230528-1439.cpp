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
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> a = {0};
        for (auto &row: mat) {
            vector<int> b;
            for (int x: a)
                for (int y: row)
                    b.push_back(x + y);
            sort(b.begin(), b.end());
            if (b.size() > k) // 保留最小的 k 个
                b.resize(k);
            a = move(b);
        }
        return a.back();
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
