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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= 0; --i)
        {
            if (m == 0)
                nums1[i] = nums2[--n];
            else if (n == 0)
                nums1[i] = nums1[--m];
            else if (nums1[m - 1] > nums2[n - 1])
                nums1[i] = nums1[--m];
            else
                nums1[i] = nums2[--n];
        }
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
