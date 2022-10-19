#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        k = (k & 0x55555555) + ((k >> 1) & 0x55555555);
        k = (k & 0x33333333) + ((k >> 2) & 0x33333333);
        k = (k & 0x0f0f0f0f) + ((k >> 4) & 0x0f0f0f0f);
        k = (k & 0x00ff00ff) + ((k >> 8) & 0x00ff00ff);
        k = (k & 0x0000ffff) + ((k >> 16) & 0x0000ffff);
        return k & 1;
    }
};

int main() {
    io;
    Solution s;
    cout << s.kthGrammar(0, 100) << endl;
    return 0;
}