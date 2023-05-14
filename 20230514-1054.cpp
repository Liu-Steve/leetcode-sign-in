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

class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        priority_queue<pr> heap;
        unordered_map<int, int> mp;
        for (int i : barcodes)
            mp[i]++;
        for (auto &[k, v] : mp)
            heap.emplace(v, k);
        int last = -1;
        vector<int> ans;
        while (!heap.empty())
        {
            auto [cnt1, val1] = heap.top();
            heap.pop();
            if (val1 == last)
            {
                auto [cnt2, val2] = heap.top();
                heap.pop();
                ans.emplace_back(val2);
                if (cnt2 > 1)
                    heap.emplace(cnt2 - 1, val2);
                heap.emplace(cnt1, val1);
                last = val2;
                continue;
            }
            ans.emplace_back(val1);
            if (cnt1 > 1)
                heap.emplace(cnt1 - 1, val1);
            last = val1;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
