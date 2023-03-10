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
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    vector<string> findLongestSubarray(vector<string> &array)
    {
        int len = array.size();
        int prefix[len + 1][2];
        prefix[0][0] = prefix[0][1] = 0;
        for (int i = 0; i < len; ++i)
        {
            if (array[i][0] >= 'A')
            {
                prefix[i + 1][0] = prefix[i][0] + 1;
                prefix[i + 1][1] = prefix[i][1];
            }
            else
            {
                prefix[i + 1][0] = prefix[i][0];
                prefix[i + 1][1] = prefix[i][1] + 1;
            }
        }
        unordered_map<int, int> h;
        int p = 0;
        int mlen = 0;
        for (int i = 0; i <= len; ++i)
        {
            int d = prefix[i][0] - prefix[i][1];
            if (h.find(d) == h.end())
            {
                h[d] = i;
                continue;
            }
            int nlen = i - h[d];
            if (nlen > mlen)
            {
                mlen = nlen;
                p = h[d];
            }
        }
        auto p1 = array.begin() + p;
        auto p2 = array.begin() + p + mlen;
        vector<string> ans(p1, p2);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vs v1 = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    for (auto _ : s.findLongestSubarray(v1))
        cout << _ << ' ';
    cout << endl;
    vs v2 = {"A","A"};
    for (auto _ : s.findLongestSubarray(v2))
        cout << _ << ' ';
    cout << endl;
    vs v3 = {"A","1"};
    for (auto _ : s.findLongestSubarray(v3))
        cout << _ << ' ';
    cout << endl;
    return 0;
}