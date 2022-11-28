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
    int minOperations(string s) {
        int n = s.size();
        int cnt = 0;
        int st = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (s[i] == '0' + st);
            st = !st;
        }
        return min(cnt, n - cnt);
    }
};

int main() {
    io;
    Solution s;
    return 0;
}