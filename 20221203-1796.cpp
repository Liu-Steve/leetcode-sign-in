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
    int secondHighest(string s) {
        int n1 = -1, n2 = -1;
        for (char ch : s)
        {
            int n = ch - '0';
            if (n < 0 || n > 9)
                continue;
            if (n > n1) {
                n2 = n1;
                n1 = n;
            } else if (n < n1 && n > n2) {
                n2 = n;
            }
        }
        return n2;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}