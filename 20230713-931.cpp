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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> arr1(matrix[0]);
        vector<int> arr2(n, 0);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int add = arr1[j];
                if (j > 0)
                    add = min(add, arr1[j - 1]);
                if (j < n - 1)
                    add = min(add, arr1[j + 1]);
                arr2[j] = add + matrix[i][j];
            }
            swap(arr1, arr2);
        }
        return *min_element(arr1.begin(), arr1.end());
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
