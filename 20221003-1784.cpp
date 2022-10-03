#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int state = 0;
        for (char ch : s) {
            if (state == 0) {
                if (ch == '0')
                    state = 1;
            }
            else
                if (ch == '1')
                    return false;
        }
        return true;
    }
};

int main() {
    io;
    Solution s;
    string str = "1";
    cout << s.checkOnesSegment(str) << endl;
    return 0;
}