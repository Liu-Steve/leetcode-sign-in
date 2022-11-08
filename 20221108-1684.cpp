#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int map = 0;
        for (char ch : allowed) {
            map |= 1 << (ch - 'a');
        }
        int res = 0;
        for (string s : words) {
            bool is = true;
            for (char ch : s) {
                if (!(map & (1 << (ch - 'a'))))
                {
                    is = false;
                    break;
                }
            }
            if (is)
                res++;
        }
        return res;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}