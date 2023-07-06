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
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum % 2 == 1)
            return {};
        vector<long long> ans;
        long long num = 2;
        while (num + num < finalSum)
        {
            ans.emplace_back(num);
            finalSum -= num;
            num += 2;
        }
        ans.emplace_back(finalSum);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
