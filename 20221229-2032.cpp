#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        uint8_t cnt[101];
        memset(cnt, 0, sizeof(cnt));
        for (auto n : nums1)
            cnt[n] |= 1;
        for (auto n : nums2)
            cnt[n] |= 2;
        for (auto n : nums3)
            cnt[n] |= 4;
        vi res;
        res.reserve(100);
        for (int i = 1; i <= 100; ++i)
            if (cnt[i] >= 5 || cnt[i] == 3)
                res.emplace_back(i);
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vi n11 = {1, 1, 3, 2};
    vi n12 = {2, 3};
    vi n13 = {3};
    vi n1 = s.twoOutOfThree(n11, n12, n13);
    for (auto n : n1)
        cout << n << ' ';
    cout << endl;
    vi n21 = {3, 1};
    vi n22 = {2, 3};
    vi n23 = {1, 2};
    vi n2 = s.twoOutOfThree(n21, n22, n23);
    for (auto n : n2)
        cout << n << ' ';
    cout << endl;
    vi n31 = {1, 2, 2};
    vi n32 = {4, 3, 3};
    vi n33 = {5};
    vi n3 = s.twoOutOfThree(n31, n32, n33);
    for (auto n : n3)
        cout << n << ' ';
    cout << endl;
    return 0;
}