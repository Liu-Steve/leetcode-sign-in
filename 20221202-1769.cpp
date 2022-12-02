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

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left = boxes[0] - '0';
        int right = 0;
        int op = 0;
        for (int i = 1; i < n; ++i) 
        {
            if (boxes[i] - '0')
            {
                right++;
                op += i;
            }
        }
        vi res(n);
        res[0] = op;
        for (int i = 1; i < n; ++i)
        {
            op += left - right;
            if (boxes[i] - '0')
            {
                left++;
                right--;
            }
            res[i] = op;
        }
        return res;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}