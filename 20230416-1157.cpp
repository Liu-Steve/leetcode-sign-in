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

class MajorityChecker
{
private:
    const int M = 15;
    unordered_map<int, vector<int>> idx;
    vector<vector<int>> subfix;

public:
    MajorityChecker(vector<int> &arr) : subfix(M, vector<int>(1, 0))
    {
        int len = arr.size();
        for (int i = 0; i < len; ++i)
        {
            if (idx.count(arr[i]))
                idx[arr[i]].emplace_back(i);
            else
                idx[arr[i]] = {i};
            int num = arr[i];
            for (int j = 0; j < M; ++j)
            {
                subfix[j].emplace_back(subfix[j][i] + (num & 1));
                num >>= 1;
            }
        }
    }

    int query(int left, int right, int threshold)
    {
        int val = 0;
        for (int i = 0; i < M; ++i)
        {
            int cnt = subfix[i][right + 1] - subfix[i][left];
            if (cnt < threshold && right - left + 1 - cnt < threshold)
                return -1;
            if (cnt >= threshold)
                val |= 1 << i;
        }
        const auto& v = idx[val];
        auto it1 = lower_bound(v.begin(), v.end(), left);
        auto it2 = upper_bound(v.begin(), v.end(), right);
        if (it2 - it1 < threshold)
            return -1;
        return val;
    }
};

int main()
{
    io;
    vi v1 = {1, 1, 2, 2, 1, 1};
    MajorityChecker m(v1);
    cout << m.query(0, 5, 4) << endl;
    cout << m.query(0, 3, 3) << endl;
    cout << m.query(2, 3, 2) << endl;
    return 0;
}