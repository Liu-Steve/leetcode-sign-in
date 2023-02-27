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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    vv mergeSimilarItems(vv &items1, vv &items2)
    {
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        vv ans;
        int len1 = items1.size();
        int len2 = items2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < len1 || idx2 < len2)
        {
            if (idx1 == len1)
                ans.emplace_back(items2[idx2++]);
            else if (idx2 == len2)
                ans.emplace_back(items1[idx1++]);
            else if (items1[idx1][0] < items2[idx2][0])
                ans.emplace_back(items1[idx1++]);
            else if (items1[idx1][0] > items2[idx2][0])
                ans.emplace_back(items2[idx2++]);
            else
            {
                ans.emplace_back(
                    vi({items1[idx1][0],
                        items1[idx1][1] + items2[idx2][1]}));
                idx1++;
                idx2++;
            }
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